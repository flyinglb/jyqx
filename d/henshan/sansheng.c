// Room: /d/henshan/sansheng.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������Ǹ����¿�ɽ��ʦ��˼��Ǵ�����˵��˼��ʦ�����������
����ʳ�����������Զ���п����ӣ���˵���ܽ��ڻ�˼��ʦ������ǧ
�꣬��ͤͤ���ǣ�������ԡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southup"   : __DIR__"jigaoming",
           "eastdown"  : __DIR__"fuyansi",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

