// by mayue

inherit ROOM;

void create()
{
        set("short", "�ݵ�");
	set("long", @LONG
���������е�һƬ�յأ����ܱ�����Ĺ��ɻ����ţ�������һƬ��
���͵Ĳݵء��ݵ����������һ��ȭͷ��С��С�����Ա�����Բ���
������¶�����ɫ������������һƬ�ž����ݵ����������ģ��������
��ȴһҲ�����ɣ�����ò�����ʲôΣ�հɣ�
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//              "east" : __DIR__"sl8",
//              "northwest" : __DIR__"sl4",
//              "west" : __DIR__"sl6",
//              "northeast" : __DIR__"sl5",
                "south" : __DIR__"sl7",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

