// /d/xiakedao/shiroom22.c ���͵� ʯ��22

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ֻ����ž֮�����ϣ������������Ӹ�����ü��������ӡ֤�书��
һ�Ե�����ȴ��Ĭ����������ָ�������ڿ��������̡�һ����Ůб
��ʯ��(wall)������ƣ�룬�Ҳ೤�����Ӷ���һ�̵��ģ���ɫ��ע��
LONG );
        set("exits", ([
                "north" : __DIR__"shihole6",
                ]));
       set("item_desc", ([
                "wall" : @WALL
ǽ�ϡ���������Ӣ����������������б�����¡����ϼ����¸�������
Сͼ�������ֳֹ��������Σ����޹��¡�ͼ�༰����֮�������ܲ�С
ע��һ��ע�ƣ��Ĳѻ��硣��һ��ע����Ի��Ԫ�����ϣ�������Ҳ��
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
