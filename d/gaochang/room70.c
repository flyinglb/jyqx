// Room: /u/mei/room70.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һƬï�ܵ����֣����з�����������Ӣ�ͷף�һ�㵭���ı�
�����������Ĳ��㣬�����ڿ���֮�С�ż����һ��������������
���Գ��ľ������ֱ���һʯɽ��ɽ�������ҷ졣
LONG
        );
        set("outdoors", "room70");
        set("objects", ([ 
        __DIR__"obj/kuzhi" : 2,
]));
        set("exits", ([ 
        "south" : __DIR__"room67",
]));
        set("outdoors", "city");
        set("item_desc", ([
        "�ҷ�" : "���ҷ�խ�����ֶ�������ȥ���Աߵ���ʯ����ʯ���ֵĿ��š����޼��񾭴�����\n", 
])); 
        setup();        
}
