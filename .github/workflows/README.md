# GitHub Actions Workflow

## Build M5Stack Projects

This workflow automatically builds both M5Stack projects when code is pushed to the repository or when pull requests are created.

### Projects Built

1. **test_key_switch_m5stack_basic**
   - Target: M5Stack Core ESP32
   - Environment: `m5stack-core-esp32`
   - Features: BLE Keyboard functionality

2. **test_key_switch_m5stack_s3**
   - Target: M5Stack Core S3
   - Environment: `m5stack-cores3`
   - Features: USB HID Keyboard functionality

### Workflow Features

- **Parallel Building**: Both projects are built in parallel using matrix strategy
- **Caching**: PlatformIO and pip dependencies are cached to speed up builds
- **Artifact Upload**: Compiled firmware binaries are uploaded as artifacts
- **Cross-platform**: Runs on Ubuntu latest

### Triggers

- Push to `main` or `master` branch
- Pull requests targeting `main` or `master` branch

### Build Artifacts

After successful builds, firmware binaries are available as downloadable artifacts:
- `test_key_switch_m5stack_basic-firmware`
- `test_key_switch_m5stack_s3-firmware`

### Dependencies

The workflow automatically installs:
- Python 3.9
- PlatformIO Core
- Required libraries as specified in each project's `platformio.ini`
