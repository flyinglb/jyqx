// Room: /t/wanjiegu/road3.c

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
����һ�����ϵĹٵ�����ͨ����ǣ�������ԭ���ء��������
�����������ַǷ����иϵ��ģ��о��̵ģ�Ҳ���������������ֺ�
�ܡ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"road4",
  "south" : __DIR__"road2",
  "northwest" : __DIR__"riverside2",
]));
        set("objects", ([
//     "/d/city/npc/walker": 2,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
