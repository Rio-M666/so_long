
#ifndef DICT_H
# define DICT_H

# include <stdio.h>

// 辞書のエントリを表す構造体
typedef struct s_dict_entry
{
	char *number;              // 数値部分
	char *text;                // 対応するテキスト
	struct s_dict_entry *next; // 次のエントリへのポインタ
}				t_dict_entry;

// 辞書ファイルをパースして辞書のリンクリストを作成する関数
t_dict_entry	*parse_dict(const char *filename);

// 辞書のメモリを解放する関数
void			free_dict(t_dict_entry *head);

#endif // DICT_H
