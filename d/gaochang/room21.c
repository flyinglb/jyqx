// Room: /u/mei/room21.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "С��");
    set("long", @LONG
��·��֪���ж������������ߣ���Щ�ط����ݱ��˻��ߣ���Щ�ط���ȫ��
ɳ����������������һ��ļž���ֻ�з紵�����ҵ�ɳɳ֮����ż��һ������
�������ȷ�Ʈ�����ʡ�
LONG
    );
    set("exits", ([ 
  "northwest" : __DIR__"room20",
  "south" : __DIR__"room71",
  "southwest" : __DIR__"room71",
  "north" : __DIR__"room71",
  "northeast" : __DIR__"room22",
  "east" : __DIR__"room71",
  "southeast" : __DIR__"room71",
  "west" : __DIR__"room71",
]));
    setup();
}
