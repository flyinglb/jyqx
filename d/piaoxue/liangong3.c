#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������Ʈѩ�ĵ��������ĵط���
����Ʈѩ�ĵ���ǧ����������̫��Ŷ��
��Ϊׯ��������ڸ����÷��ַ�Ʈѩ��
�����ɱ���ۣ�
LONG);
        set("exits", ([
                "south" : __DIR__"dayuan2",
        ]));

        set("objects", ([
                __DIR__"npc/mu-ren" : 5,
        ]));

        setup();
        replace_program(ROOM);
}