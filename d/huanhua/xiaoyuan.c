// xiaoyuan.c
// written by tree

inherit ROOM;

void create()
{
	set("short", "ʮ����");
	set("long", @LONG
��ǰ�ľ��£�����������һ����ǰ���Ȼ��һ������ĺɻ��أ��м���������
����С���ڳ�����Ϸ������ɻ����ϣ���һ��ʮ���ţ�������Ȼ������ʮ���š���
����������������ի,���߻���һ����߷�����������Ǵ����ˡ����æ�ӿ��˲�����
LONG);
	set("exits", ([ 
	"out" : __DIR__"damen",
	"west" : __DIR__"chufang",
	"north" : __DIR__"dating",
	"east" : __DIR__"kufang",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
