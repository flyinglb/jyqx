
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������������ػ���ľ�ô�����ֻ��һ�Ű����Ϲ�������
���ƣ��м�һ��д�š���������֮λ�������һ��д�š�������ƽ����
֣֮λ����������һ���ľ (baimu)��������������ȫ��Ѫ�֡�������
һ������(duilian)�������ǲ������ϱ����ǰ�����
LONG );
	set("valid_startroom", 1);
	set("exits", ([
	"south" : __DIR__"andao10",
	"north" : __DIR__"tuzai",
	"east"  : __DIR__"ceting",
	]));
	set("item_desc", ([
"baimu" : 
HIR "\n  ֻ����ľ��д����������У��ظ����������˵�ͬ��������\n"
"����԰���£�ԼΪ�ֵܣ��պ�����������Ϊһ�ҡ�����Ϊ����\n"
"�ݵ�Ϊĸ, ��Ϊ�֣���Ϊ��ã��������ģ�һѩǰ�ܣ�˳��\n"
"�е����ָ��������ѪΪ�ˣ�����������\n" NOR,
"duilian":
HIC "\n����߸ԣ�һ��Ϫɽǧ����\n" NOR +
HIG "�ų��󺣣����Ӻ�ˮ������\n" NOR,
	]));
	set("objects", ([
		CLASS_D("yunlong") + "/chen" : 1
	]));
//	set("no_clean_up", 0);
	setup();
        "/clone/board/tiandihui_b"->foo();
}

int valid_leave(object me, string dir)
{
	if (dir== "north")
	message("vision","գ�ۼ䣬���׳���ͻȻ����һ���ˡ�\n","/d/city2/tuzai");
	return ::valid_leave(me, dir);
}
