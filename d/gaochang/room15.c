// Room: /u/mei/room15.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "ɳĮ����");
        set("long", @LONG
����µ���ɳ�Ѿ�������һ��СС�ĺ��������������ǰ�������ˮ��Ȼ
ֻ�ж�ָ��ȴ���峺���ڿ��ȵķ��У���ˮ������ô��������һ�������ɱ�
����ע����С�������һ��ʯ��(shibei)��
    ����������һ��ѩ�׵�ɽ���������������ۣ��羴֮�ģ���Ȼ������
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room13",
  "west" : __DIR__"room17",
  "north" : __DIR__"room41",
]));
        set("no_new_clean_up", 0);
        set("outdoors", "room15");

        set("item_desc", ([
                "shibei" : "�������أ���ȥ�߲���\n",
        ]));
        setup();
        replace_program(ROOM);
}
