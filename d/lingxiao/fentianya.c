//LUCAS 2000-6-18
// fentianya.c ������

inherit ROOM;
#include <ansi.h> 

void init();
void create()
{
        set("short", "������");
        set("long", @LONG 
������������ǵ����ա������¡�������ȥ��ֻ���������
�ϣ�����һ����խ�ֻ��ı��ݣ�ѩ��Ʈ�䣬���ǻ����ǿ����
��У�����һ��ҡҡ��׹�ĸо���
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
            "southdown" : __DIR__"sroad6",
            "up" : __DIR__"bingti",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


