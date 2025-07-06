# M5Stack キーボードプロジェクト

M5StackをキーボードとしてPCに接続し、ボタン操作で文字や絵文字を入力するプロジェクトです。

## プロジェクト構成

このプロジェクトは2つのバージョンに分かれています：

### 1. test_key_switch_m5stack_basic (BLE版)
- **対象デバイス**: M5Stack Core (ESP32)
- **接続方式**: Bluetooth Low Energy (BLE)
- **特徴**: ワイヤレス接続、バッテリー駆動可能
- **制限**: 絵文字入力に制限あり

### 2. test_key_switch_m5stack_s3 (USB HID版)
- **対象デバイス**: M5Stack CoreS3 (ESP32-S3)
- **接続方式**: USB HID
- **入力方式**: タッチスクリーン（画面下部の3つのタッチエリア）
- **特徴**: 有線接続、絵文字完全対応、低遅延
- **制限**: USBケーブル接続が必要

## 機能比較

| 機能 | Basic版 (BLE) | S3版 (USB HID) |
|------|---------------|----------------|
| Aボタン | "A" | "A" |
| Bボタン | ":D" | "😆" |
| Cボタン | "Hello!" | "🍭✒" |
| 接続方式 | Bluetooth | USB |
| 絵文字対応 | ❌ | ✅ |
| 遅延 | 低〜中 | 極低 |
| 移動性 | 自由 | 制限あり |

## 使い分けの指針

### BLE版 (Basic) を選ぶ場合
- M5Stack Coreしか持っていない
- ワイヤレス接続が必要
- 移動しながら使用したい
- 絵文字入力は不要

### USB HID版 (S3) を選ぶ場合
- M5Stack CoreS3を持っている
- 絵文字入力が必要
- 低遅延が重要
- 有線接続でも問題ない

## セットアップ

### 共通の前提条件
- PlatformIO環境のセットアップ
- 適切なUSBケーブル

### Basic版のセットアップ
```bash
cd test_key_switch_m5stack_basic
/usr/bin/python3 -m platformio run --target upload
```

### S3版のセットアップ
```bash
cd test_key_switch_m5stack_s3
/usr/bin/python3 -m platformio run --target upload
```

## 技術的背景

### 絵文字入力の問題

**問題**: ESP32のBLE HIDライブラリは絵文字（マルチバイトUTF-8文字）を正しく処理できません。

**解決策**: ESP32-S3のネイティブUSB HID機能を使用することで、絵文字を含むUnicode文字を正しく処理できます。

### アーキテクチャの違い

#### BLE版 (ESP32)
```
M5Stack Core → BLE → PC/スマホ
- BLE HIDプロトコル使用
- 外部ライブラリ依存
- マルチバイト文字制限
```

#### USB HID版 (ESP32-S3)
```
M5Stack CoreS3 → USB → PC
- ネイティブUSB HID
- Arduino標準ライブラリ
- 完全Unicode対応
```

## 開発履歴

1. **初期実装**: BLE版で絵文字入力を試行
2. **問題発見**: 絵文字が文字化けする問題を確認
3. **原因調査**: BLE HIDライブラリの制限を特定
4. **解決策実装**: ESP32-S3のUSB HID版を追加開発

## 今後の拡張可能性

- より多くのボタン入力パターン
- カスタマイズ可能な文字設定
- 特殊キー組み合わせ（Ctrl+C等）
- マクロ機能
- 設定保存機能

## ライセンス

このプロジェクトはオープンソースです。自由に改変・配布してください。

## 貢献

バグ報告や機能追加の提案は、GitHubのIssueまたはPull Requestでお願いします。
