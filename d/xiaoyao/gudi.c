// gudi.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "�ȵ�");
        set("long", @LONG
�����ö��ߺ�����������Խ��Խ��ɽ��Ҳ�𽥱����б������������
����ô���ͱ����ˣ����ڵ���ȵ��ˡ�ֻ�����������һ�����ٲ���������
�գ��������£�������һ���峺�쳣�Ĵ��֮�С���Ϊ׳�ۡ�
LONG );
        set("exits", ([
//               "out" : __DIR__"damen",
//               "north" : __DIR__"shishi1",
		"up" : __DIR__"yanfeng",
		"west" : __DIR__"hubian",
	]));
	set("outdoors", "xiaoyao" );
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
