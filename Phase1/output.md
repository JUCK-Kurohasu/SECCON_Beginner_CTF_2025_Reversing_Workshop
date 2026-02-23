SECCON Beginners向け演習①問題セット（大量生成版）を作成します！

---

# 演習① 問題セット（AI禁止・50分想定）

## 📊 問題一覧

| # | 問題名 | 難易度 | 想定時間 | カテゴリ | 学べること |
|---|--------|--------|----------|----------|------------|
| 1 | welcome | ★☆☆☆☆ | 3分 | ソースコード | 基本的なC言語読解 |
| 2 | hidden_flag | ★☆☆☆☆ | 5分 | strings | stringsコマンド |
| 3 | base64_easy | ★★☆☆☆ | 7分 | エンコード | Base64デコード |
| 4 | strcmp_basic | ★★☆☆☆ | 8分 | ソースコード | strcmp理解 |
| 5 | multiple_strings | ★★☆☆☆ | 8分 | strings+grep | grepパターン |
| 6 | xor_simple | ★★★☆☆ | 10分 | 難読化 | XOR暗号 |
| 7 | reverse_string | ★★★☆☆ | 10分 | 難読化 | 文字列反転 |
| 8 | function_chain | ★★★☆☆ | 12分 | Ghidra | 関数呼び出し追跡 |
| 9 | split_flag | ★★★☆☆ | 12分 | Ghidra | 複数関数の結合 |
| 10 | xor_shift | ★★★★☆ | 15分 | 難読化 | XOR+ビットシフト |

---

## 問題詳細

### 【問題1】welcome ★☆☆☆☆ (3分)

**ファイル**: `welcome.c`（ソースコード配布）

```c
// welcome.c
#include <stdio.h>
#include <string.h>

int main() {
    char flag[] = "ctf4b{w3lc0me_to_reversing}";
    char input[100];
    
    printf("Enter the flag: ");
    scanf("%99s", input);
    
    if (strcmp(input, flag) == 0) {
        printf("Correct!\n");
    } else {
        printf("Wrong!\n");
    }
    
    return 0;
}
```

**想定解法**:
- ソースコードを読むだけ
- `flag[]` の中身がフラグ

**学べること**: 
- strcmpの仕組み
- 変数の初期化

---

### 【問題2】hidden_flag ★☆☆☆☆ (5分)

**ファイル**: `hidden_flag`（ELFバイナリ、strip済み）

```c
// hidden_flag.c
#include <stdio.h>

int main() {
    char secret[] = "ctf4b{str1ngs_c0mm4nd_is_p0w3rful}";
    printf("Can you find the hidden flag?\n");
    printf("Hint: Try using basic Linux commands!\n");
    return 0;
}
```

**コンパイル**:
```bash
gcc hidden_flag.c -o hidden_flag
strip hidden_flag
```

**想定解法**:
```bash
strings hidden_flag | grep ctf4b
# または
strings hidden_flag | grep "ctf4b{"
```

**学べること**:
- stringsコマンドの基本
- grepとの組み合わせ

---

### 【問題3】base64_easy ★★☆☆☆ (7分)

**ファイル**: `base64_easy`（ELFバイナリ）

```c
// base64_easy.c
#include <stdio.h>

int main() {
    // "ctf4b{b4s364_dec0d1ng_is_easy}" in Base64
    char encoded[] = "Y3RmNGJ7YjRzMzY0X2RlYzBkMW5nX2lzX2Vhc3l9";
    
    printf("Encoded flag: %s\n", encoded);
    printf("Hint: This looks like Base64...\n");
    
    return 0;
}
```

**想定解法**:
```bash
strings base64_easy | grep -E '^[A-Za-z0-9+/=]{30,}$'
# 見つけたBase64文字列を
echo "Y3RmNGJ7YjRzMzY0X2RlYzBkMW5nX2lzX2Vhc3l9" | base64 -d
```

**学べること**:
- Base64エンコーディングの認識
- base64コマンド

---

### 【問題4】strcmp_basic ★★☆☆☆ (8分)

**ファイル**: `strcmp_basic.c`（ソースコード配布）

```c
// strcmp_basic.c
#include <stdio.h>
#include <string.h>

int check_password(char *input) {
    char password[] = "sup3r_s3cr3t_p4ssw0rd";
    return strcmp(input, password) == 0;
}

int main() {
    char input[100];
    
    printf("Enter password: ");
    scanf("%99s", input);
    
    if (check_password(input)) {
        printf("Access granted!\n");
        printf("Flag: ctf4b{strcmp_ch3ck_byp4ss3d}\n");
    } else {
        printf("Access denied!\n");
    }
    
    return 0;
}
```

**想定解法**:
- `check_password`関数を読む
- `password[]` の値 = `sup3r_s3cr3t_p4ssw0rd`
- 実行して入力すればフラグ表示

**学べること**:
- 関数の呼び出し
- strcmpのロジック

---

### 【問題5】multiple_strings ★★☆☆☆ (8分)

**ファイル**: `multiple_strings`（ELFバイナリ）

```c
// multiple_strings.c
#include <stdio.h>

int main() {
    char fake1[] = "fake{this_is_not_the_flag}";
    char fake2[] = "ctf{almost_but_not_quite}";
    char real[] = "ctf4b{gr3p_p4tt3rn_m4st3r}";
    char fake3[] = "flag{nice_try}";
    
    printf("There are many strings...\n");
    printf("But only one is the real flag!\n");
    
    return 0;
}
```

**想定解法**:
```bash
strings multiple_strings | grep "ctf4b{"
```

**学べること**:
- フラグフォーマットの重要性
- grepパターンマッチング

---

### 【問題6】xor_simple ★★★☆☆ (10分)

**ファイル**: `xor_simple`（ELFバイナリ）

```c
// xor_simple.c
#include <stdio.h>

int main() {
    // "ctf4b{x0r_1s_r3v3rs1bl3}" XOR 0x42
    unsigned char encrypted[] = {
        0x21, 0x26, 0x24, 0x76, 0x20, 0x3b, 0x3e, 0x2d,
        0x3e, 0x37, 0x3a, 0x3e, 0x37, 0x31, 0x3e, 0x30,
        0x31, 0x30, 0x31, 0x37, 0x20, 0x30, 0x31, 0x66
    };
    
    printf("Encrypted flag found at %p\n", encrypted);
    printf("Hint: XOR key is 0x42\n");
    
    return 0;
}
```

**想定解法**:
```python
enc = [0x21, 0x26, 0x24, 0x76, 0x20, 0x3b, 0x3e, 0x2d,
       0x3e, 0x37, 0x3a, 0x3e, 0x37, 0x31, 0x3e, 0x30,
       0x31, 0x30, 0x31, 0x37, 0x20, 0x30, 0x31, 0x66]

flag = ''.join(chr(c ^ 0x42) for c in enc)
print(flag)
```

**学べること**:
- XOR暗号の基本
- Pythonでの復号

---

### 【問題7】reverse_string ★★★☆☆ (10分)

**ファイル**: `reverse_string`（ELFバイナリ）

```c
// reverse_string.c
#include <stdio.h>
#include <string.h>

int main() {
    // "ctf4b{str1ng_r3v3rs4l}" を反転
    char reversed[] = "}l4s3v3r_gn1rts{b4ftc";
    
    printf("Reversed flag: %s\n", reversed);
    printf("Hint: Something is backwards...\n");
    
    return 0;
}
```

**想定解法**:
```bash
strings reverse_string | grep "}" | rev
# または
echo "}l4s3v3r_gn1rts{b4ftc" | rev
```

**学べること**:
- 文字列反転
- revコマンド

---

### 【問題8】function_chain ★★★☆☆ (12分)

**ファイル**: `function_chain`（ELFバイナリ、strip済み）

```c
// function_chain.c
#include <stdio.h>

void print_part3() {
    printf("_ch41n}");
}

void print_part2() {
    printf("funct10n");
    print_part3();
}

void print_part1() {
    printf("ctf4b{");
    print_part2();
}

int main() {
    printf("Flag parts are scattered across functions!\n");
    print_part1();
    printf("\n");
    return 0;
}
```

**想定解法**:
```bash
# 実行するだけ
./function_chain

# またはstrings
strings function_chain | grep ctf4b
# → 分割されているので見つからない

# Ghidraで main → print_part1 → print_part2 → print_part3 を追う
```

**学べること**:
- 関数呼び出しチェーンの追跡
- 実行してみることの重要性

---

### 【問題9】split_flag ★★★☆☆ (12分)

**ファイル**: `split_flag`（ELFバイナリ）

```c
// split_flag.c
#include <stdio.h>
#include <string.h>

char part1[] = "ctf4b{";
char part2[] = "spl1t_";
char part3[] = "fl4g_";
char part4[] = "p4rts}";

void show_flag() {
    char full[100];
    strcpy(full, part1);
    strcat(full, part2);
    strcat(full, part3);
    strcat(full, part4);
    printf("Flag: %s\n", full);
}

int main() {
    printf("The flag is split into multiple parts!\n");
    show_flag();
    return 0;
}
```

**想定解法**:
```bash
# 方法1: 実行
./split_flag

# 方法2: stringsで各パーツを探して結合
strings split_flag | grep "ctf4b{"
strings split_flag | grep "_"
# → 手動で結合

# 方法3: Ghidraで show_flag 関数を見る
```

**学べること**:
- strcpy/strcatの仕組み
- 複数変数の結合

---

### 【問題10】xor_shift ★★★★☆ (15分)

**ファイル**: `xor_shift`（ELFバイナリ）

```c
// xor_shift.c - あなたが作ったコードそのまま
#include <stdio.h>
#include <string.h>

unsigned char XOR(unsigned char input){
    return input ^ 0xAA;
}

unsigned char SHIFT4(unsigned char c){
    return (c << 4) | (c >> 4);
}

int main(){
    char flag[] = "ctf4b{XOR_stream_bitshift}";
    
    printf("Encrypted-flag:0x");
    for(int idx=0; idx<strlen(flag); idx++){
        printf("%02x", SHIFT4(XOR(flag[idx])));
    }
    printf("\n");
    
    return 0;
}
```

**想定解法**:
```python
encrypted = "9cedcce98c1d2f5e8f5f9ded8dfcbc7c5f8c3ced9d2c3ccced7d"
hex_bytes = [encrypted[i:i+2] for i in range(0, len(encrypted), 2)]

flag = ""
for h in hex_bytes:
    c = int(h, 16)
    # SHIFT4の逆（同じ操作）
    unshifted = ((c << 4) | (c >> 4)) & 0xFF
    # XORの逆
    original = unshifted ^ 0xAA
    flag += chr(original)

print(flag)
```

**学べること**:
- XOR + ビットシフトの組み合わせ
- 復号スクリプト作成

---

## 🎁 ボーナス問題（時間が余った人向け）

### 【問題11】rot13_flag ★★☆☆☆ (8分)

```c
// rot13_flag.c
#include <stdio.h>

int main() {
    // "ctf4b{rot13_is_classic}" をROT13
    char encoded[] = "pgs4o{ebg13_vf_pynffvp}";
    
    printf("Encoded: %s\n", encoded);
    printf("Hint: Caesar cipher variant...\n");
    
    return 0;
}
```

**想定解法**:
```bash
echo "pgs4o{ebg13_vf_pynffvp}" | tr 'A-Za-z' 'N-ZA-Mn-za-m'
```

---

### 【問題12】hex_dump ★★☆☆☆ (8分)

```c
// hex_dump.c
#include <stdio.h>

int main() {
    // "ctf4b{h3x_t0_4sc11}" を16進数表示
    printf("Hex flag: ");
    char flag[] = "ctf4b{h3x_t0_4sc11}";
    for (int i = 0; flag[i]; i++) {
        printf("%02x", flag[i]);
    }
    printf("\n");
    
    return 0;
}
```

**想定解法**:
```bash
./hex_dump
# 出力された16進数を
echo "637466346..." | xxd -r -p
# または Python
python3 -c "print(bytes.fromhex('637466346...').decode())"
```

---

## 📦 問題配布形式

### ディレクトリ構成
```
reversing_workshop/
├── README.txt
├── easy/
│   ├── 01_welcome.c
│   ├── 02_hidden_flag
│   ├── 03_base64_easy
│   └── ...
├── medium/
│   ├── 06_xor_simple
│   ├── 07_reverse_string
│   └── ...
└── hard/
    └── 10_xor_shift
```

---

## 🎯 推奨タイムスケジュール（50分）

```
00:00-00:05  説明（5分）
00:05-00:20  Easy問題（15分）
             → 問題1-5から3-4問
00:20-00:35  Medium問題（15分）
             → 問題6-9から2-3問
00:35-00:50  Hard問題（15分）
             → 問題10 または複数問題
```

---

## 💡 各問題の学習目標

| 問題 | 学習目標 |
|------|----------|
| 1-2 | ソースコード読解、stringsコマンド |
| 3-5 | エンコーディング、grepパターン |
| 6-7 | 暗号化の基本、復号スクリプト |
| 8-9 | Ghidra基本、関数追跡 |
| 10 | 複合的な難読化解析 |

---

これで**50分で段階的に学べる問題セット**が完成です！
必要なら各問題のバイナリ生成スクリプトや、解説スライドも作成できます！