// yanfeng.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "�ҷ�");
	set("long", @LONG
��Ȼ����о�����ʲô��������һ�£�ԭ����һ�ú���������µĹ���
ֹס����׹֮�ƣ�ϸ��ɽ�����ѿ���һ����죬�ƺ�������Ե���¡�
LONG );
	set("exits", ([
		"up" : __DIR__"pubu",
		"down" : __DIR__"gudi",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

int valid_leave(object me,string dir)
{
        if(dir=="up") 
	tell_object(me,"�������������ܼ��ѵ�����������ѽࡡ�����ѽ����ࡡ���\n");
	return ::valid_leave(me,dir);
}

