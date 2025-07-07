#!/bin/bash

# Fedora Development Environment Setup Script
# This script installs essential development tools and applications

set -e  # Exit on any error

echo "🚀 Starting Fedora Development Environment Setup..."
echo "=================================================="

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    echo -e "${GREEN}[INFO]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Update system first
print_status "Updating system packages..."
sudo dnf update -y
sudo dnf upgrade -y

# Install essential packages first
print_status "Installing essential packages..."
sudo dnf install -y curl wget git

# Install RPM Fusion repositories (needed for some packages)
print_status "Installing RPM Fusion repositories..."
sudo dnf install -y https://download1.rpmfusion.org/free/fedora/rpmfusion-free-release-$(rpm -E %fedora).noarch.rpm
sudo dnf install -y https://download1.rpmfusion.org/nonfree/fedora/rpmfusion-nonfree-release-$(rpm -E %fedora).noarch.rpm

# Enable Flathub repository
print_status "Enabling Flathub repository..."
sudo dnf install -y flatpak
flatpak remote-add --if-not-exists flathub https://dl.flathub.org/repo/flathub.flatpakrepo

# Install g++
print_status "Installing g++ compiler..."
sudo dnf install -y gcc-c++

# Install VSCode
print_status "Installing Visual Studio Code..."
sudo rpm --import https://packages.microsoft.com/keys/microsoft.asc
sudo sh -c 'echo -e "[code]\nname=Visual Studio Code\nbaseurl=https://packages.microsoft.com/yumrepos/vscode\nenabled=1\ngpgcheck=1\ngpgkey=https://packages.microsoft.com/keys/microsoft.asc" > /etc/yum.repos.d/vscode.repo'
sudo dnf install -y code

# Install Zed Editor via curl
print_status "Installing Zed Editor via curl..."
curl -f https://zed.dev/install.sh | sh
# Add Zed to PATH for all users
sudo ln -sf ~/.local/bin/zed /usr/local/bin/zed 2>/dev/null || true

# Install Brave Browser
print_status "Installing Brave Browser..."
sudo dnf install -y dnf-plugins-core
sudo dnf config-manager --add-repo https://brave-browser-rpm-release.s3.brave.com/brave-browser.repo
sudo rpm --import https://brave-browser-rpm-release.s3.brave.com/brave-core.asc
sudo dnf install -y brave-browser

# Install Google Chrome
print_status "Installing Google Chrome..."
wget -O /tmp/google-chrome.rpm https://dl.google.com/linux/direct/google-chrome-stable_current_x86_64.rpm
sudo dnf install -y /tmp/google-chrome.rpm
rm /tmp/google-chrome.rpm

# Install GNOME Tweaks
print_status "Installing GNOME Tweaks..."
sudo dnf install -y gnome-tweaks

# Install gdm-settings via Flathub
print_status "Installing gdm-settings via Flathub..."
flatpak install -y flathub io.github.realmazharhussain.GdmSettings

# Install fastfetch
print_status "Installing fastfetch..."
sudo dnf install -y fastfetch

# Install some additional useful development tools
print_status "Installing additional development tools..."
sudo dnf install -y \
    vim \
    nano \
    htop \
    tree \
    unzip \
    zip \
    make \
    cmake \
    gdb \
    valgrind

# Update system one more time
print_status "Final system update..."
sudo dnf update -y

# Clean up package cache
print_status "Cleaning up package cache..."
sudo dnf clean all

print_status "Setup completed successfully! 🎉"
echo "=================================================="
echo "Installed packages:"
echo "✓ g++ (GCC C++ compiler)"
echo "✓ Visual Studio Code"
echo "✓ Zed Editor (via curl)"
echo "✓ Brave Browser"
echo "✓ Google Chrome"
echo "✓ GNOME Tweaks"
echo "✓ gdm-settings (via Flathub)"
echo "✓ fastfetch"
echo "✓ Additional development tools"
echo ""
echo "You may need to:"
echo "1. Restart your system for all changes to take effect"
echo "2. Configure your development environment"
echo "3. Sign in to your browsers and sync your settings"
echo "4. Run 'fastfetch' to see your system info"
echo "5. Launch gdm-settings with: flatpak run io.github.realmazharhussain.GdmSettings"
echo ""
print_status "Enjoy your new Fedora development environment!"
