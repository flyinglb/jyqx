// /d/xiakedao/shishi11.c ���͵� ʯ��11

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ű�������г������أ���������������������ɽ��֮�ʡ���
��Ҳ�ǻ���������Ĭ�������ظ�����ϰ�书,���ȴ��֪Ϊ�����˼�
֧��ʯ��(wall)��Ͷ���˴�Ƭ��Ӱ��
LONG );
        set("exits", ([
                "west"  : __DIR__"shihole3",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š�������캥���������֡��ֵ��·��̵����������
���캥�Ĺ��¡���˵���캥ɱ��Ϊ��������֮��̻�سֵ��������⺷
֮ɫ��κ�����޼���һ��վ������ɫ������
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
