// Room: /t/wanjiegu/road2.c

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
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road3",
  "south" : __DIR__"road1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
