// /d/xiakedao/shiroom10.c ���͵� ʯ��10

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����ȴҲ�������������һ�˺��ԣ����ǹ���ƣ�룬�Ѿ�����
˯ȥ��һ�������������ֶ���������������ʯ��(wall)����������
վ��һλ��ò�ٸ����ԱߵĻ�ѽ�Ҫȼ����ҡҷ���������Ϻ�����
�˶�����һЩ����ı��С�
LONG );
        set("exits", ([
                "north" : __DIR__"shihole3",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š��ѽ�ϥǰ�᡹�������֡��ֵ��·�δ��ͼ����ֻ��
���СС���Ը�������д����ע�͡�һ�в����ǣ��Ź���ʫ�ƣ�һ��
�������ķ�����һ��������ʯ�������ɽˮͨ־��������ʯ���ݳ�
�ƽ��������죬���˶�Ĥ�ݡ���Ϊ���������ȼ���ӬͷС����������
����֮��
WALL
        ]));
        set("objects", ([
                __DIR__"master/hongantong" : 1,
                __DIR__"master/suquan"    : 1,
        ]));
/*
  �����̿�ɽ��ʦ �鰲ͨ(Hong antong)
  �����̽������� ����(Su quan)
*/
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
