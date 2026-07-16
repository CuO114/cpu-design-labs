import fs from "node:fs/promises";
import path from "node:path";
import { FileBlob, SpreadsheetFile } from "@oai/artifact-tool";

const root = "D:/CpuDesign";
const outDir = path.join(root, ".tmp/control-signals/previews");
await fs.mkdir(outDir, { recursive: true });

for (const relativePath of [
  "homework/数据通路表、控制信号取值表_miniRV - 模板.xlsx",
  "指令速查表_miniRV.xlsx",
]) {
  const workbook = await SpreadsheetFile.importXlsx(
    await FileBlob.load(path.join(root, relativePath)),
  );
  const tag = relativePath.startsWith("homework") ? "template" : "reference";
  const summary = await workbook.inspect({
    kind: "workbook,sheet,table,region",
    maxChars: 20000,
    tableMaxRows: 60,
    tableMaxCols: 40,
    tableMaxCellChars: 120,
  });
  await fs.writeFile(path.join(outDir, `${tag}-inspect.ndjson`), summary.ndjson, "utf8");

  const sheets = await workbook.inspect({ kind: "sheet", include: "id,name", maxChars: 5000 });
  await fs.writeFile(path.join(outDir, `${tag}-sheets.ndjson`), sheets.ndjson, "utf8");
  const names = [...sheets.ndjson.matchAll(/"name":"([^"]+)"/g)].map((match) => match[1]);
  for (const [index, sheetName] of names.entries()) {
    const preview = await workbook.render({
      sheetName,
      autoCrop: "all",
      scale: 1.5,
      format: "png",
    });
    await fs.writeFile(
      path.join(outDir, `${tag}-${index + 1}.png`),
      new Uint8Array(await preview.arrayBuffer()),
    );
  }
}
