// Room: /u/mei/room44.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
ת�˼����䣬��һ�Ų��������д��˳�ȥ����ʱ���ô��ˡ���ǰһƬ�����
�����϶�����һ�����ٲ���ˮ���Ľ����չ�ӳ�գ��ֳ�һ���ʺ磬���ܻ����β
�ӻ������䣬��ӳ�ڱ��̵ĺ�ˮ֮�У�����Ī����Զ���Ǵ�Ƭ���ƽԭ���ޱ�
�޼ʵ������ȥ��������ӡ�·����һ��ʯ��(shibei)��
LONG
        );
        set("outdoors", "room44");
        set("no_new_clean_up", 0);
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room45",
  "south" : __DIR__"caoyuan1",
  "east" : __DIR__"room43",
]));

        set("item_desc", ([
                "shibei" : "�������أ��ϴ��������\n",
        ]));
        setup();
        replace_program(ROOM);
}
