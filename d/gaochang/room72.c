// Room: /d/gaochang/room72.c// This is a room made by roommaker. write by Fan. :)
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
  "south" : __DIR__"room72",
  "southwest" : __DIR__"room72",
  "northeast" : __DIR__"room72",
  "north" : __DIR__"room72",
  "east" : __DIR__"room72",
  "southeast" : __DIR__"room72",
  "west" : __DIR__"room72",
]));

        setup();
}
