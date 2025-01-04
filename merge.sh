#!/bin/bash

# 出力ファイル名
output_file="merged.txt"

# 出力ファイルを初期化
> "$output_file"

# 現在のディレクトリ内の .c と .h ファイルを検索
for file in *.c *.h; do
    if [ -f "$file" ]; then
        echo "// File: $file" >> "$output_file"
        # ファイルの10行目以降を出力ファイルに追加
        tail -n +11 "$file" >> "$output_file"
        echo -e "\n" >> "$output_file"  # ファイル間に改行を挿入
    fi
done

echo "統合が完了しました: $output_file"
