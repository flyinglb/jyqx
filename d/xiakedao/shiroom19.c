// /d/xiakedao/shiroom19.c ���͵� ʯ��19

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ＫΪ�Ͱ�������Ը�֮�˱�Ҫ��ͷ�����ڽ���������һ֧��
�ѣ�����ľ���ȼΪ�ҽ����ڻ谵�Ĺ����У�����һ����ϥ��������
��ʯ��(wall)�Ȼ��š�ֻ����ָ���棬�����ޱȡ�
LONG );
        set("exits", ([
                "west"  : __DIR__"shihole5",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š�ǧ���׳ʿ���������֡��·�����������캥����
Я�ֶ��У����ǹŷ硰�����С�ԭ�⡣����һ��С������Ի��֪����
ˮ��������ɽ��֪�߶������߾�����ע��ׯ����ˮƪ����֪��ʱֹ��
��ӯ��β��к֮��
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
