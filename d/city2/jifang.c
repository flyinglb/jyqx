
inherit ROOM;
#include <ansi.h>


void create()
{
	set("short", "�������");
	set("long", @LONG
������һ��ӵ�����ٶ�̨586�ĳ����ģ����.�����ϵ������ϵ����Ϣϵ��
Ӧ��ϵ�ȸ�ϵ�������ǣ�������������������������������������ϯ,Ȼ����Ȼ
û��һ����play MUD��ǽ������һ��ͨ�� (tonggao)���Աߵļ����ϰ���һ��
С�ڰ�(board).
LONG );
	set("exits", ([ 
		"west" : __DIR__"xukong",
		"north" : __DIR__"ximenwai",
	]));

       set("item_desc", ([
                "tonggao" :   
  HIR "������֣������,���´�ϺСϺ�Ա�ͣ��һ��:\n" NOR +
  HIR "��������ʮ������,������Ϻ������Ϊ��:\n" NOR +
  HIM "��ɽ��ʮ�Ĵ�����[���]׿�ư�(zyb)\n" NOR +
  HIM "�����ŵ���������[Ц�ȿ޺�]˾������(huak)\n" NOR +
  HIM "�䵱���������� ��ͣ��(xiao)\n" NOR +
  HIR ".......\n" NOR,
 "board" :   HIC "��ע��,���»������ڱ����ô���Ѳ�������ʹ�ã�\n" NOR +
  HIM "55�Ż���60�Ż���78�Ż���136�ţ�����������\n" NOR,
	]));

	set("valid_startroom",1);
	set("objects", ([ 
		"/d/city2/npc/zhuge" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
    int i;
    object *inv;
if(dir=="west")
 {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
		if(objectp(present("zhuge", environment(me)))&&living(present("zhuge", environment(me))))
                    return notify_fail("�����̫��ǰ���һ����"+
                        RANK_D->query_rude(me) + "�����ߣ���\n");
	return ::valid_leave(me, dir);
 }
return ::valid_leave(me, dir);
}

