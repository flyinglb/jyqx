// Room: /d/huanggon/tinglang3.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ܵ���������.������ϲ�˵Ļ���,վ�����,��Լ���õ�����
������Ů����Ц������,�����������������,�Եþ�������,��������
�Ĺ��ͦ�ϵ�.
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"qihedian",
  "east" : "/include/net/kunning",
]));
        set("no_clean_up", 0);
        set("outdoors", "huangon");

        setup();
        replace_program(ROOM);
}
