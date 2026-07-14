# CPU Design Labs

本仓库用于 CPU 设计课程实验的组内协作。

- GitHub 团队仓库 `origin`：<https://github.com/CuO114/cpu-design-labs>
- 课程指导书仓库 `upstream`：<https://git.cs-lab.top/cslab/cpu-design>
- 默认协作分支：`main`

## 仓库内容

- `miniRV_basic_ego1/miniRV_basic/miniRV.xpr`：实验 1 的 Vivado 工程入口。
- `miniRV_basic_ego1/miniRV_basic/src/`：RTL、仿真、约束、COE 和 Vivado IP 配置源文件。
- `数据通路表、控制信号取值表_miniRV - 模板.xlsx`：需要协作填写并提交的表格。
- `指令速查表_miniRV.xlsx`、课程 PDF：实验参考材料。
- `docs/`：课程指导书，由课程 `upstream/main` 更新。

Vivado 的缓存、综合/实现结果、比特流、日志以及可由 `.xci` 重新生成的 IP 输出不会提交。新克隆仓库后若 Vivado 提示 IP 输出缺失，在 Vivado 中执行 **Generate Output Products**。

## 第一次使用

### 仓库创建者

当前工作区已经配置好两个远端，可以用以下命令检查：

```powershell
git remote -v
```

正常情况下应同时看到：

```text
origin    https://github.com/CuO114/cpu-design-labs.git
upstream  https://git.cs-lab.top/cslab/cpu-design.git
```

### 新加入的队友

队友首先克隆 GitHub 仓库，然后手动添加课程仓库。Git 不会通过克隆自动复制 `upstream` 配置。

```powershell
git clone https://github.com/CuO114/cpu-design-labs.git
cd cpu-design-labs
git remote add upstream https://git.cs-lab.top/cslab/cpu-design.git
git remote -v
```

在开始修改前确认身份配置：

```powershell
git config user.name
git config user.email
```

若没有输出，设置自己的 Git 提交身份：

```powershell
git config --global user.name "你的名字或 GitHub 用户名"
git config --global user.email "你的 GitHub 邮箱"
```

## 日常协作流程

推荐每个任务使用独立分支并通过 Pull Request 合并。不要让多人直接同时修改 `main`。

### 1. 开始任务前同步 `main`

```powershell
cd D:\CpuDesign
git switch main
git pull --ff-only origin main
git status
```

`git status` 应显示工作区干净。如果有未提交修改，先提交、暂存或确认其来源，不要直接拉取后再处理。

### 2. 创建任务分支

```powershell
git switch -c feature/任务名称
```

建议使用以下命名：

- `feature/...`：实现新指令、模块或数据通路。
- `fix/...`：修复仿真、综合或功能错误。
- `docs/...`：修改表格、报告或协作文档。

分支名使用简短英文和连字符，例如：

```powershell
git switch -c feature/add-alu-ops
git switch -c fix/load-sign-extension
git switch -c docs/control-signal-table
```

### 3. 检查并暂存修改

修改和验证完成后，先检查改了什么：

```powershell
git status
git diff
```

只暂存本次任务涉及的文件：

```powershell
git add -- miniRV_basic_ego1/miniRV_basic/src/rtl/cpu_core.v
git add -- miniRV_basic_ego1/miniRV_basic/src/rtl/Controller.v
git add -- "数据通路表、控制信号取值表_miniRV - 模板.xlsx"
```

文件名含空格或中文标点时必须使用完整文件名并加引号。`--` 表示后续内容都是路径，可避免文件名被误当成命令参数。

检查即将提交的内容：

```powershell
git diff --cached
git status
```

不要习惯性使用 `git add -A`，否则容易混入日志、临时文件或其他人的未完成修改。

### 4. 创建提交

```powershell
git commit -m "实现算术类指令控制逻辑"
```

提交信息应说明做了什么，避免使用 `update`、`test`、`修改文件` 等无法追踪目的的描述。一个提交尽量只处理一个明确任务。

### 5. 上传到 GitHub

第一次上传当前分支：

```powershell
git push -u origin HEAD
```

同一分支后续继续上传：

```powershell
git push
```

上传后打开 GitHub 仓库，点击 **Compare & pull request**，检查变更并创建 Pull Request。也可以使用 GitHub CLI：

```powershell
gh pr create --web
```

Pull Request 合并后同步并删除本地任务分支：

```powershell
git switch main
git pull --ff-only origin main
git branch -d feature/任务名称
```

### 小修改直接提交到 `main`

只有在组员确认不会并行修改时，才对很小的文档修正使用以下流程：

```powershell
git switch main
git pull --ff-only origin main
git add -- <本次修改的文件>
git commit -m "说明本次修改"
git push origin main
```

禁止对共享的 `main` 使用 `git push --force`。

## 与队友同步和解决冲突

### 让任务分支获取最新 `main`

```powershell
git switch main
git pull --ff-only origin main
git switch feature/任务名称
git merge main
```

没有冲突时可以继续开发并执行 `git push`。出现冲突时：

1. 运行 `git status` 查看冲突文件。
2. 打开文本文件，处理 `<<<<<<<`、`=======`、`>>>>>>>` 标记。
3. 完成后执行 `git add -- <冲突文件>`。
4. 执行 `git commit` 完成合并，再运行 `git push`。

如果发现合并方向错误且还没有提交，可取消本次合并：

```powershell
git merge --abort
```

不要在不了解影响时使用 `git reset --hard`，它会直接丢弃本地修改。

### 表格文件协作

`.xlsx` 是二进制文件，Git 无法逐单元格合并。协作时遵守以下规则：

1. 在群里明确当前由谁编辑某个表格。
2. 编辑前先执行 `git pull --ff-only origin main`。
3. 一次完成一小部分后及时提交和推送。
4. 该 Pull Request 合并前，其他人不要编辑同一个表格。
5. 如果表格发生冲突，由组员共同确定保留哪个版本，再手工补录另一版本的内容。

## Vivado 文件管理

应提交的内容包括：

- `.xpr` 工程入口和 `.xci` IP 配置。
- `.v`、`.vh`、`.sv` 等 RTL 与仿真源文件。
- `.xdc` 约束文件。
- `.coe`、`.asm` 测试或初始化文件。
- 有协作价值的 `.wcfg` 波形配置。

不会提交的内容包括：

- `.Xil`、`*.cache`、`*.gen`、`*.runs`、`*.sim` 等运行目录。
- `vivado.log`、`vivado.jou`、综合检查点和比特流。
- 可由 `.xci` 重新生成的 IP 输出文件。

检查某个文件为什么没有出现在 `git status` 中：

```powershell
git check-ignore -v -- <文件路径>
git status --ignored
```

如果自己编写的 RTL 被 Vivado 放进了被忽略的工程生成目录，应将源文件移到 `miniRV_basic_ego1/miniRV_basic/src/` 下，再在 Vivado 工程中重新引用，不能强行提交生成目录。

## 更新课程指导书

先确认已配置 `upstream`：

```powershell
git remote get-url upstream
```

如果提示不存在，执行：

```powershell
git remote add upstream https://git.cs-lab.top/cslab/cpu-design.git
```

确保 `main` 工作区干净，然后更新并上传：

```powershell
git switch main
git pull --ff-only origin main
.\scripts\update-course.ps1
git push origin main
```

脚本会获取 `upstream/main` 并合并到团队 `main`。如果课程更新与本组文件冲突，脚本会停在标准 Git 冲突状态，不会覆盖未提交修改。

## 常见问题

### `pathspec ... did not match any files`

Git 找不到你输入的路径，常见原因是文件名不完整、缺少扩展名或文件名含空格但没有加引号。例如实际文件名是：

```text
数据通路表、控制信号取值表_miniRV - 模板.xlsx
```

正确命令：

```powershell
git add -- "数据通路表、控制信号取值表_miniRV - 模板.xlsx"
```

可先查找准确名称，或输入部分名称后按 `Tab` 自动补全：

```powershell
Get-ChildItem *数据通路表*
```

### `nothing to commit, working tree clean`

表示 Git 没有检测到新的受控修改。依次检查：

```powershell
git status
git diff
git status --ignored
```

文件可能没有实际变化、已经提交，或被 `.gitignore` 排除。

### `rejected` 或 `non-fast-forward`

说明远端分支比本地更新。不要强制推送，先同步：

```powershell
git switch main
git pull --ff-only origin main
```

如果自己正在任务分支开发，按“让任务分支获取最新 `main`”一节合并最新代码后再推送。

### 暂存了错误文件

取消暂存但保留本地修改：

```powershell
git restore --staged -- <文件路径>
```

丢弃某个文件尚未提交的修改会不可恢复，执行前必须检查路径：

```powershell
git restore -- <文件路径>
```

### `not a git repository`

当前终端不在仓库目录中：

```powershell
cd D:\CpuDesign
git status
```

### GitHub 登录失效

```powershell
gh auth status
gh auth login
```

不要把访问令牌、设备码或密码提交到仓库或发送给组员。

## 最终提交

课程要求最终压缩包只包含报告 PDF、汇编/COE 和 Verilog 源文件，不包含完整 Vivado 工程或生成物。提交前应按指导书要求整理独立提交目录，并确认压缩包小于 100 MB。
