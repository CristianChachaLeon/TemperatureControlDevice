# Set properlly Enviroment to work arv for windows
#-----------------------------------------------------
# Tools
# - Vscode
# - Avr-gcc /avrdude /avr-gdb

# List tools to verify
$tools = @("code", "avr-gcc")

# Function to check avr-gcc y avrdude
function Find-Tool {
    param ([string]$toolName)
    try {
        (Get-Command $toolName -ErrorAction Stop).Source
        Write-Host "$toolName already installed."
        return 1
    } catch {
        Write-Host "$toolName is not installed."
        return 0
    }
}

# Function to install VSCODE
function Install-VSCode {
    $installerUrl = "https://aka.ms/win32-x64-user-stable"
    $installerPath = "$env:TEMP\VSCodeInstaller.exe"

    Invoke-WebRequest -Uri $installerUrl -OutFile $installerPath
    Start-Process -FilePath $installerPath -Args "/silent /mergetasks=!runcode" -Wait
    Remove-Item -Path $installerPath
}

#function to install win-avr
function Install-WinAVR {
    $url = "https://sourceforge.net/projects/winavr/files/WinAVR/20100110/WinAVR-20100110-install.exe/download"
    $output = "$env:USERPROFILE\Downloads\WinAVR-20100110-install.exe"
    Write-Host "$output"
    Invoke-WebRequest -UserAgent "Wget" -Uri  $url -OutFile $output
    Start-Process -FilePath $output -Wait
    Remove-Item $output
    Write-Host "WinAVR has been installed."
}

# Check tools and install
foreach ($tool in $tools) {
    
    $isInstalled = Find-Tool $tool

    if($isInstalled -eq 0 ){
	Write-Host "Installing... $tool "
        if($tool -eq "code"){
            Install-VSCode
        }elseif ($tool -eq "avr-gcc"){
            Install-WinAVR
        }else{
           Write-Host "Unknown package $tool"
        }
	}
}

