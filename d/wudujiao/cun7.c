// Room: /u/star/cun7.c
// star 1998/12/04 ��������Ȩ���У����������޸Ĵ���


inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����С���ʯ��·�ϣ����Զ�������ʯ���ɵķ��ݡ�������һ��ѧ�ã�
���洫�����ʵĶ������� 
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"northwest" : __DIR__"cun5",
		"southeast" : __DIR__"cun8",
		"southwest" : __DIR__"cun6",
		"east" : __DIR__"minju7",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

