// liangong6.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������˹����ڵ�һ�����ߣ����еıڻ����ṹ���ܣ�ɫ�����ޣ���̬������
�������������������һ�ɷ�����ﲼ�õķǳ��򵥣���������������Ҫ��
ԭ���������е���ɮ����֮����
LONG
	);
        set("exits", ([ 
		"south" : __DIR__"huayuan2", 		
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
