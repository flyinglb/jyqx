// /d/xiakedao/shiroom18.c ���͵� ʯ��18

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ʯ��֮��ƽƽ���棬Ҳ�������д��书����ָ��ʯ��(wall)�໥
���ۡ�ż������ĬȻ��������ͷ������������ˮ������ش˴�����Ϫ
��֮�¡�����ʯש�ϱ鲼��̦������С�ı�Ҫ������
LONG );
        set("exits", ([
                "north" : __DIR__"shihole5",
        ]));
        set("item_desc", ([
                "wall" : @WALL
��ǽ�ϡ��������𾪡��������ֿ������ֱ�š�����ͼ����Ϊ���أ�
����һֻ����̤��ƽ�أ������������֮�ϼ���������а�����֮
�࣬�໥������Ҳ������֡��ײ���ע��׳��ֺ�����ף����ڡ�
WALL
        ]));
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_beg", 1);
        setup();
}
void init()
{
        add_action("do_study","think");
}
#include "/d/xiakedao/shiroom.h"
