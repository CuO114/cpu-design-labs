[CmdletBinding()]
param()

$ErrorActionPreference = "Stop"

function Invoke-Git {
    & git @args
    if ($LASTEXITCODE -ne 0) {
        throw "Git command failed: git $($args -join ' ')"
    }
}

$repoRoot = (& git rev-parse --show-toplevel).Trim()
if ($LASTEXITCODE -ne 0) {
    throw "Run this script from inside the CPU design repository."
}

Push-Location $repoRoot
try {
    $branch = (& git branch --show-current).Trim()
    if ($branch -ne "main") {
        throw "Switch to main before updating the course guide. Current branch: $branch"
    }

    if (& git status --porcelain) {
        throw "Commit or stash local changes before updating the course guide."
    }

    # The course Gitea endpoint is reachable directly. Bypass machine-wide
    # proxies here because some HTTPS proxy setups break its TLS handshake.
    Invoke-Git -c http.proxy= -c https.proxy= fetch upstream main

    $pending = [int]((& git rev-list --count HEAD..upstream/main).Trim())
    if ($pending -eq 0) {
        Write-Host "Course guide is already up to date."
        return
    }

    Invoke-Git merge --no-edit upstream/main
    Write-Host "Merged $pending new upstream commit(s). Review the result, then push main to origin."
}
finally {
    Pop-Location
}
