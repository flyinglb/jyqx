// /d/xiakedao/shiroom15.c ���͵� ʯ��15
inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�������Ũ�أ����������˲��پƴ����«����������˵���Ѿ�
�������壬أ�������ﲻͣ���ƣ����ĵ�ģ��ʯ��(wall)�ϵ�ͼ����
�����������һ��Ů���ڱǶ�����������֮ɫ��
LONG );
        set("exits", ([
                "west"  : __DIR__"shihole4",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š��ۻ������᡹�������֡�����̵���³��������ɽ
�ŵĹ��£����е��ֺ��д������࣬Ω��ΩФ�������ֻ���������Ҷ��
�����衣
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
