// /d/xiakedao/shiroom03.c ���͵� ʯ��3

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���з���������������Ӱ���ڶ���Ѹ���쳣�ر��ܣ�ֱ������
�����硣һ��������Ʈ�ݣ���һ��������Ƚ�������һ��������
��֮����ȴҲʮ��Ѹ�ݡ����˱�����أ�Բ�ͣ���ۣ�����������ƽ
�����Ա�ʯ��(wall)��Ҳ����ͼ���֡�
LONG );
        set("exits", ([
                "west"  : __DIR__"shihole1",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š������հ����������֡��ֵ��·�����һƥ����
���ױ��У���������������������������з���һ�㡣ֻ��һ������
���ƺ��ڲ�����ǰ��ӿ��ֱ�������Ʊڷɳ���
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
