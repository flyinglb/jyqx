// Room: /u/mei/room11.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "��Į��ɳ");
        set("long", @LONG
�����ڴ��ڿ������¯��ɳĮ�У��ȵ�����������͸������������������
�ķ�������ʲôҲ���������������۹����ķ�ɳ����ʲôҲ����������ؼ�
�·�ֻʣ����һ���ˡ�����»�����������ɳ�������ı����ĸо���
LONG
        );
        set("exits", ([ /* sizeof() == 8 */
  "south" : __DIR__"room13",
  "southwest" : __DIR__"room13",
  "north" : __DIR__"room12",
  "northeast" : __DIR__"room13",
  "east" : __DIR__"room13",
  "southeast" : __DIR__"room13",
  "west" : __DIR__"room13",
  "northwest" : __DIR__"room10",
]));
//        set("no_new_clean_up", 0);

        setup();
}
int valid_leave(object me, string dir)
{
        int current_water;
        current_water = (int)me->query("water");
        if (!current_water) return 1;
        if (current_water>0 && current_water<20) {
            me->set("water",0);
        }
        if (current_water>20) {
            me->set("water",current_water-20);
        }

    return 1;
}

