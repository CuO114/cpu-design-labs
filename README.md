# CPU Design Labs

本仓库用于 CPU 设计课程实验的组内协作。仓库的 Git 历史继承自课程指导书，课程仓库配置为 `upstream`，团队自己的 GitHub 仓库配置为 `origin`。

## 当前内容

- `miniRV_basic_ego1/miniRV_basic/miniRV.xpr`：实验 1 的 Vivado 工程入口。
- `miniRV_basic_ego1/miniRV_basic/src/`：RTL、仿真、约束、COE 和 Vivado IP 配置源文件。
- `数据通路表、控制信号取值表_miniRV - 模板.xlsx`：需要协作填写并提交的表格。
- `指令速查表_miniRV.xlsx`、课程 PDF：实验参考材料。
- `docs/`：课程指导书，由课程 `upstream/main` 更新。

Vivado 的运行目录、缓存、综合/实现结果、比特流以及可由 `.xci` 重新生成的 IP 输出不会提交。新克隆仓库后若 Vivado 提示 IP 输出缺失，在 Vivado 中执行 **Generate Output Products** 即可。

## 协作流程

每项功能从最新的 `main` 建立独立分支，完成后推送到 GitHub 并通过 Pull Request 合并：

```powershell
git switch main
git pull --ff-only origin main
git switch -c feature/<简短任务名>

# 修改并验证后
git add <本次修改的文件>
git commit -m "完成某项功能"
git push -u origin HEAD
```

不要直接提交 Vivado 生成目录，也不要用 `git add -A` 混入与当前任务无关的文件。二进制表格无法自动合并；同一时间只安排一人编辑同一个 `.xlsx`，其他人通过 Pull Request 接收结果。

## 更新课程指导书

确保 `main` 工作区干净，然后执行：

```powershell
.\scripts\update-course.ps1
git push origin main
```

脚本会获取 `upstream/main` 并合并到团队 `main`。如果课程更新与本组文件发生冲突，脚本会停在标准 Git 冲突状态，需要解决冲突后再提交；不会覆盖未提交修改。

## 最终提交

课程要求最终压缩包只包含报告 PDF、汇编/COE 和 Verilog 源文件，不包含完整 Vivado 工程或生成物。提交前应按指导书要求重新整理独立的提交目录，并确认压缩包小于 100 MB。
