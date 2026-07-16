import fs from "node:fs/promises";
import path from "node:path";
import { FileBlob, SpreadsheetFile } from "@oai/artifact-tool";

const root = "D:/CpuDesign";
const inputPath = path.join(root, "homework/数据通路表、控制信号取值表_miniRV - 模板.xlsx");
const outputDir = path.join(root, "outputs/control-signals");
const outputPath = path.join(outputDir, "数据通路表、控制信号取值表_miniRV_控制信号已完成.xlsx");
await fs.mkdir(outputDir, { recursive: true });

const workbook = await SpreadsheetFile.importXlsx(await FileBlob.load(inputPath));
const sheet = workbook.worksheets.getItemAt(1);

// The template stops drawing the table at row 40. Extend its existing row style.
for (let row = 41; row <= 52; row += 1) {
  sheet.getRange(`B${row}:M${row}`).copyFrom(sheet.getRange("B40:M40"), "all");
}

// ram_wop is present in the completed datapath but omitted from the value table.
sheet.unmergeCells("F15:M15");
sheet.getRange("N15:N52").copyFrom(sheet.getRange("M15:M52"), "all");
sheet.mergeCells("F15:N15");
sheet.getRange("F15").values = [["控制信号"]];
sheet.getRange("N16").values = [["ram_wop"]];
sheet.getRange("M15:N52").format.columnWidth = 14;
sheet.getRange("O15:O52").clear({ applyTo: "formats" });

const rows = [
  ["add",   "110011",  "0",   "0",      "PC4",    "1", "WB_ALU", "-",      "ADD",   "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["sub",   "110011",  "0",   "100000", "PC4",    "1", "WB_ALU", "-",      "SUB",   "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["auipc", "10111",   "-",   "-",      "PC4",    "1", "WB_ALU", "U_TYPE", "ADD",   "SEL_PC",  "SEL_EXT", "0",         "0"],
  ["sll",   "110011",  "1",   "0",      "PC4",    "1", "WB_ALU", "-",      "SLL",   "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["srl",   "110011",  "101", "0",      "PC4",    "1", "WB_ALU", "-",      "SRL",   "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["srli",  "10011",   "101", "0",      "PC4",    "1", "WB_ALU", "I_TYPE", "SRL",   "SEL_RS1", "SEL_EXT", "0",         "0"],
  ["sra",   "110011",  "101", "100000", "PC4",    "1", "WB_ALU", "-",      "SRA",   "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["srai",  "10011",   "101", "100000", "PC4",    "1", "WB_ALU", "I_TYPE", "SRA",   "SEL_RS1", "SEL_EXT", "0",         "0"],
  ["xor",   "110011",  "100", "0",      "PC4",    "1", "WB_ALU", "-",      "XOR",   "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["xori",  "10011",   "100", "-",      "PC4",    "1", "WB_ALU", "I_TYPE", "XOR",   "SEL_RS1", "SEL_EXT", "0",         "0"],
  ["lb",    "11",      "0",   "-",      "PC4",    "1", "WB_RAM", "I_TYPE", "ADD",   "SEL_RS1", "SEL_EXT", "BYTE_EXT",  "0"],
  ["lbu",   "11",      "100", "-",      "PC4",    "1", "WB_RAM", "I_TYPE", "ADD",   "SEL_RS1", "SEL_EXT", "BYTE_UEXT", "0"],
  ["lh",    "11",      "1",   "-",      "PC4",    "1", "WB_RAM", "I_TYPE", "ADD",   "SEL_RS1", "SEL_EXT", "HALF_EXT",  "0"],
  ["lhu",   "11",      "101", "-",      "PC4",    "1", "WB_RAM", "I_TYPE", "ADD",   "SEL_RS1", "SEL_EXT", "HALF_UEXT", "0"],
  ["sw",    "100011",  "10",  "-",      "PC4",    "0", "-",      "S_TYPE", "ADD",   "SEL_RS1", "SEL_EXT", "0",         "WORD_WE"],
  ["sb",    "100011",  "0",   "-",      "PC4",    "0", "-",      "S_TYPE", "ADD",   "SEL_RS1", "SEL_EXT", "0",         "BYTE_WE"],
  ["sh",    "100011",  "1",   "-",      "PC4",    "0", "-",      "S_TYPE", "ADD",   "SEL_RS1", "SEL_EXT", "0",         "HALF_WE"],
  ["jalr",  "1100111", "0",   "-",      "JUMP",   "1", "WB_PC4", "I_TYPE", "ADD",   "SEL_RS1", "SEL_EXT", "0",         "0"],
  ["mul",   "110011",  "0",   "1",      "PC4",    "1", "WB_ALU", "-",      "MUL",   "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["mulh",  "110011",  "1",   "1",      "PC4",    "1", "WB_ALU", "-",      "MULH",  "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["mulhu", "110011",  "11",  "1",      "PC4",    "1", "WB_ALU", "-",      "MULHU", "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["div",   "110011",  "100", "1",      "PC4",    "1", "WB_ALU", "-",      "DIV",   "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["divu",  "110011",  "101", "1",      "PC4",    "1", "WB_ALU", "-",      "DIVU",  "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["rem",   "110011",  "110", "1",      "PC4",    "1", "WB_ALU", "-",      "REM",   "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["remu",  "110011",  "111", "1",      "PC4",    "1", "WB_ALU", "-",      "REMU",  "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["slt",   "110011",  "10",  "0",      "PC4",    "1", "WB_ALU", "-",      "SLT",   "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["slti",  "10011",   "10",  "-",      "PC4",    "1", "WB_ALU", "I_TYPE", "SLT",   "SEL_RS1", "SEL_EXT", "0",         "0"],
  ["sltu",  "110011",  "11",  "0",      "PC4",    "1", "WB_ALU", "-",      "SLTU",  "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["sltiu", "10011",   "11",  "-",      "PC4",    "1", "WB_ALU", "I_TYPE", "SLTU",  "SEL_RS1", "SEL_EXT", "0",         "0"],
  ["or",    "110011",  "110", "0",      "PC4",    "1", "WB_ALU", "-",      "OR",    "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["and",   "110011",  "111", "0",      "PC4",    "1", "WB_ALU", "-",      "AND",   "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["andi",  "10011",   "111", "-",      "PC4",    "1", "WB_ALU", "I_TYPE", "AND",   "SEL_RS1", "SEL_EXT", "0",         "0"],
  ["blt",   "1100011", "100", "-",      "BRANCH", "0", "-",      "B_TYPE", "LT",    "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["bge",   "1100011", "101", "-",      "BRANCH", "0", "-",      "B_TYPE", "GE",    "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["bltu",  "1100011", "110", "-",      "BRANCH", "0", "-",      "B_TYPE", "LTU",   "SEL_RS1", "SEL_RS2", "0",         "0"],
  ["bgeu",  "1100011", "111", "-",      "BRANCH", "0", "-",      "B_TYPE", "GEU",   "SEL_RS1", "SEL_RS2", "0",         "0"],
];

const padBinary = (value, width) => value === "-" ? value : value.padStart(width, "0");
const paddedRows = rows.map((row) => [
  row[0],
  padBinary(row[1], 7),
  padBinary(row[2], 3),
  padBinary(row[3], 7),
  ...row.slice(4),
]);

sheet.getRange("C5:E12").values = [
  ["0010011", "000", "-"],
  ["0010011", "110", "-"],
  ["0010011", "001", "0000000"],
  ["0110111", "-",   "-"],
  ["0000011", "010", "-"],
  ["1100011", "000", "-"],
  ["1100011", "001", "-"],
  ["1101111", "-",   "-"],
];
sheet.getRange("B17:N52").values = paddedRows;
sheet.getRange("C5:C12").format.numberFormat = "0000000";
sheet.getRange("D5:D12").format.numberFormat = "000";
sheet.getRange("E5:E12").format.numberFormat = "0000000";
sheet.getRange("C17:C52").format.numberFormat = "0000000";
sheet.getRange("D17:D52").format.numberFormat = "000";
sheet.getRange("E17:E52").format.numberFormat = "0000000";
sheet.getRange("B15:N52").format.wrapText = false;
sheet.getRange("B17:N52").format.horizontalAlignment = "center";
sheet.getRange("B17:N52").format.verticalAlignment = "center";
sheet.getRange("B41:N52").format.borders = {
  preset: "all",
  style: "thin",
  color: "#000000",
};

const keyRange = await workbook.inspect({
  kind: "table",
  sheetId: sheet.name,
  range: "B15:N52",
  include: "values,formulas",
  tableMaxRows: 45,
  tableMaxCols: 15,
  maxChars: 30000,
});
await fs.writeFile(path.join(outputDir, "control-table-inspect.ndjson"), keyRange.ndjson, "utf8");

const errors = await workbook.inspect({
  kind: "match",
  searchTerm: "#REF!|#DIV/0!|#VALUE!|#NAME\\?|#N/A",
  options: { useRegex: true, maxResults: 100 },
  summary: "final formula error scan",
});
await fs.writeFile(path.join(outputDir, "formula-errors.ndjson"), errors.ndjson, "utf8");

for (let index = 0; index < 2; index += 1) {
  const current = workbook.worksheets.getItemAt(index);
  const preview = await workbook.render({
    sheetName: current.name,
    autoCrop: "all",
    scale: index === 1 ? 1.5 : 1,
    format: "png",
  });
  await fs.writeFile(
    path.join(outputDir, `sheet-${index + 1}-preview.png`),
    new Uint8Array(await preview.arrayBuffer()),
  );
}

const output = await SpreadsheetFile.exportXlsx(workbook);
await output.save(outputPath);
await fs.writeFile(path.join(outputDir, "done.txt"), outputPath, "utf8");
