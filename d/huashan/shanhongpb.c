//Room: shanhongpb.c ɽ���ٲ�
//Date: Oct. 2 1997 by Venus
inherit ROOM;
#include <ansi.h>
string look_hongshui();
int do_lian(string arg);

void create()
{
      set("short","ɽ���ٲ�");
      set("long",@LONG
������һ��Ͽ�ȣ�ÿ���꼾ɽ�鱬��ʱ���γ���һ��εΪ׳�۵�
�ٲ�����˵�������������������������ɾ��������������ġ�����
��ȥ�ȿգ�ֻʣ�¿��ȵ�ɽ�Ⱥͱ��ڵĺ�ˮ(hongshui)��
LONG);
      set("outdoors", "xx");
      set("no_clean_up", 0);
      set("item_desc", ([
          "hongshui" : (: look_hongshui :),
      ]));
      set("exits",([ /* sizeof() == 1 */
          "southwest"     : __DIR__"shaluo",
      ]));
      setup();
}
string look_hongshui()
{
	return
"����һ�ɱ��ڲ�Ϣ�ĺ�ˮ��ˮ�������и������ڷ��⣬���㶨��\n"
"��ϸһ����������ֻ������ˮ�淴����չ���ˡ�\n";
}
void init()
{
	add_action("lian", "lian");
	add_action("lian", "practice");
}

int lian(string arg)
{
	string skillname;
	int skill, skill_basic, times, pertimes;
	object me=this_player();
	if (!arg)
        {
		write("��Ҫ��ʲô�书��\n");
                return 1;
        }
	if ( (sscanf(arg, "%s %d", arg, times)!=2 ))
		return notify_fail("ָ���ʽ��practice|lian <��������> <����>\n");
	if ( times < 1 || times > 30)
		return notify_fail("��ϰ�����������һ�Σ������ܳ�����ʮ�Ρ�\n");
	if (arg!="sword")
        {
		write("ɽ����������û���������书��\n");
                return 1;
        }
	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");
	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");

	for (pertimes = 1; pertimes <=times ; pertimes ++)
	{
		skill_basic = me->query_skill(arg, 1);
		skill = me->query_skill(skillname, 1);
		if( skill < 1 )
		return notify_fail("�����û��ѧ������ܰɣ������ȥ��̱��ˡ�\n");
		if( skill_basic < 1 )
		return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
		if( skill_basic/2 <= skill/3 )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

		notify_fail("�����ڲ�����ϰ����ܡ�\n");
		if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

		notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");
		if (skill*skill*skill/10 > (int)me->query("combat_exp")) 
		{
			return notify_fail("Ҳ����ȱ��ʵս���飬�����ϰ��û��������\n");
			return 1;
		}

		if( SKILL_D(skillname)->practice_skill(me) )
		{
			me->improve_skill(skillname, skill_basic/2 +1, skill_basic > skill? 0: 1);
			write(HIY"�������γ�ˢ�����������"+to_chinese(skillname)+"���н����ˣ�\n"NOR);
		}
		else return 0;
	}
}
