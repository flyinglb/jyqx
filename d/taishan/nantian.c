// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ʮ���̣��������̩ɽ������ڴ��������︽��ɽ�£�
Ⱥɽ�����أ����������ƣ���ؿ������޿���״������������
���߿ɵ�һ���м��������߱����¹۷壬���������ǵ���ʶ�֮·��
LONG );
	set("exits", ([
		"eastup" : __DIR__"tianjie",
		"northup" : __DIR__"yuhuang",
		"west" : __DIR__"yueguan",
		"southdown" : __DIR__"shengxian",
	]));
	set("objects",([
		__DIR__"npc/jiang" : 1,
		__DIR__"npc/wei-shi3" : 2,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "taishan");
	setup();
}

int valid_leave(object me, string dir)
{
//        object ob1, ob2, ob3;
        object ob1, ob3;
	string mengzhu, shangshan, fae;
	
	if(!( ob1 = find_living("mengzhu")) )
	ob1 = load_object("/clone/npc/meng-zhu");
	mengzhu = ob1->query("winner");

//         if(!( ob2 = find_living("shangshan")) )
//         ob2 = load_object("/clone/npc/shang-shan");
//        shangshan = ob2->query("winner");

	if(!( ob3 = find_living("fae")) )
	ob3 = load_object("/clone/npc/fa-e");
	fae = ob3->query("winner");

	if( dir == "northup" ) { 
		if( present("jiang baisheng", environment(me)) 
                && !wizardp(me)
		&& me->query("id") != mengzhu 
		&& me->query("id") != shangshan 
		&& me->query("id") != fae )
			return notify_fail("����ʤ������ס��˵����������æ�����ڲ�����ͣ�����ɽȥ�ɣ�\n");
		else if( me->query("id") == mengzhu ) {
			message_vision(HIY "\n����ʤ�ϻ̳Ͽֵ���$N�򵹿�ͷ�������������������꣬���꣬�����꣡\n" NOR, me);
		}	
		else if( me->query("id") == shangshan ) {
			message_vision(HIY "\n����ʤ�Ϲ��Ͼ�����$N�ݵ�����������ʹ�����ã� ���½���ʤ�μ����ˣ�\n" NOR, me);
		}	
		else if( me->query("id") == fae ) {
			message_vision(HIY "\n����ʤ�Ϲ��Ͼ�����$N�ݵ�����������ʹ�����ã� ���½���ʤ�μ����ˣ�\n" NOR, me);
		}	
	}

	return ::valid_leave(me, dir);
}
