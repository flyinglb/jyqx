// /d/xiakedao/shiroom20.c ���͵� ʯ��20

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������������������������ʵ����˱��ˣ������Բ�֮���ƺ�Ҫ
վ�����ȡ���λ�������ڳ��л����ڹ������������߸����𡣼�����
���߾�����ʯ��(wall)��������ɫ���š�
LONG );
        set("exits", ([
                "east"  : __DIR__"shihole5",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š��Ӻմ����ǡ��������֡��·�ͼ����Ϊ�򵥣�����
һ�������ڿն���Զ��ȴ���ƻ���̫��֮�Ρ�һ��ע��д��ͼ����
�У��ղ��ɾã��᲻���ء�ͼ����ע��������͡��������գ�������
��Ȼ��
WALL
        ]));
        set("objects", ([
                __DIR__"master/du-nan"   : 1,
                __DIR__"master/du-e" : 1,
                __DIR__"master/du-jie" : 1,
                __DIR__"master/ai-laozhe" : 1,
                __DIR__"master/gao-laozhe" : 1,
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
