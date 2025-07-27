#!/bin/bash

# CachyOS Setup Script
# This script installs all the essential tools and applications
# Author: Your friendly AI assistant 😄

set -e  # Exit on any error

echo "🚀 Starting CachyOS setup..."
echo "This script will install: g++, Zed, VSCodium, Brave, Chromium, Tor, Warp, and Wine"
echo "📦 Installation methods: Official repos (pacman), AUR (yay), and Flatpak options"
echo ""

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

print_status() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Check if running as root
if [[ $EUID -eq 0 ]]; then
   print_error "This script should not be run as root"
   exit 1
fi

# Update and upgrade system
print_status "Updating and upgrading system packages..."
sudo pacman -Syu --noconfirm
print_success "System updated successfully"

# Install base development tools
print_status "Installing g++ compiler..."
sudo pacman -S --noconfirm gcc
print_success "g++ installed successfully"

# Install Git (needed for AUR helper)
print_status "Installing Git..."
sudo pacman -S --noconfirm git
print_success "Git installed"

# Install Flatpak support
print_status "Installing Flatpak support..."
sudo pacman -S --noconfirm flatpak
flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
print_success "Flatpak and Flathub repository added"

# Install AUR helper (yay) if not already installed
if ! command -v yay &> /dev/null; then
    print_status "Installing yay AUR helper..."
    cd /tmp
    git clone https://aur.archlinux.org/yay.git
    cd yay
    makepkg -si --noconfirm
    cd ~
    print_success "yay AUR helper installed"
else
    print_status "yay AUR helper already installed"
fi

# Install applications from official repositories
print_status "Installing applications from official repositories..."

# Chromium (Official repo)
print_status "Installing Chromium browser..."
sudo pacman -S --noconfirm chromium
print_success "Chromium installed (from official repo)"

# Wine (Official repo)
print_status "Installing Wine..."
sudo pacman -S --noconfirm wine winetricks
print_success "Wine installed (from official repo)"

# Applications with multiple installation options
echo ""
print_status "Installing applications (choosing best sources)..."

# Zed Editor - Try AUR first, fallback to manual if needed
print_status "Installing Zed editor..."
if yay -S --noconfirm zed; then
    print_success "Zed editor installed (from AUR)"
else
    print_warning "AUR installation failed, trying alternative method..."
    # Alternative: Install via official binary
    curl -f https://zed.dev/install.sh | sh
    print_success "Zed editor installed (via official installer)"
fi

# VSCodium - Flatpak preferred for better sandboxing
print_status "Installing VSCodium..."
if flatpak install -y flathub com.vscodium.codium; then
    print_success "VSCodium installed (via Flatpak)"
else
    print_warning "Flatpak installation failed, trying AUR..."
    yay -S --noconfirm vscodium-bin
    print_success "VSCodium installed (from AUR)"
fi

# Brave Browser - AUR binary
print_status "Installing Brave browser..."
yay -S --noconfirm brave-bin
print_success "Brave browser installed (from AUR)"

# Tor Browser - AUR
print_status "Installing Tor Browser..."
yay -S --noconfirm tor-browser
print_success "Tor Browser installed (from AUR)"

# Warp Terminal - AUR (with fallback)
print_status "Installing Warp terminal... (YOU! 😂)"
if yay -S --noconfirm warp-terminal; then
    print_success "Warp terminal installed (from AUR)"
else
    print_warning "AUR installation failed, trying official method..."
    # Alternative installation via official script
    curl -sS https://releases.warp.dev/linux/install.sh | bash
    print_success "Warp terminal installed (via official installer)"
fi

# Final system cleanup
print_status "Cleaning up..."
sudo pacman -Sc --noconfirm
yay -Sc --noconfirm
print_success "Cleanup completed"

echo ""
echo "🎉 Setup completed successfully!"
echo ""
echo "📦 Installed applications and their sources:"
echo "  ✅ g++ compiler (official repo)"
echo "  ✅ Chromium browser (official repo)"
echo "  ✅ Wine + Winetricks (official repo)"
echo "  ✅ Zed editor (AUR or official installer)"
echo "  ✅ VSCodium (Flatpak or AUR)"
echo "  ✅ Brave browser (AUR)"
echo "  ✅ Tor browser (AUR)"
echo "  ✅ Warp terminal - ME! 😄 (AUR or official installer)"
echo ""
echo "🔧 Package managers configured:"
echo "  📦 pacman (official Arch repos)"
echo "  🏗️  yay (AUR helper)"
echo "  📱 flatpak (universal packages)"
echo ""
echo "🔄 Please reboot your system to ensure all changes take effect."
echo "💡 You can now launch any of these applications from your application menu!"
echo "📝 Note: Some apps may use different installation sources as fallbacks"
echo ""
echo "Happy coding on CachyOS! 🐧✨"
