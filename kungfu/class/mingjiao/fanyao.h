// FanYao.h
// modified by long

#include <ansi.h>

string* names = ({
	"shuo bude",
	"zhou dian",
	"zhang zhong",
	"peng yingyu",
	"leng qian",
	"yin tianzheng",
	"zhang wuji",
});

string ask_me()
{
	mapping my_fam, skl; 
	object fighter, me, room, monk;
	string *sname;

	int i,j;

	fighter = this_player();
	me = this_object();
	my_fam  = me->query("family");

	skl = fighter->query_skills();
	if (sizeof(skl) <= 1)
		return RANK_D->query_respect(fighter) + 
		"���������������ʸ񴳹���ʥ����";
	sname  = keys(skl);
	for(i=0; i<sizeof(skl); i++) {
		if (skl[sname[i]] < 80) 
		return RANK_D->query_respect(fighter) + 
		"���������������ʸ񴳹���ʥ����";
	}

	if( fighter->query("guangming_winner") )
		return RANK_D->query_respect(fighter) + 
		"��Ȼ��������ʥ���󣬿ɲ�Ҫ�÷�ң�������Ц��";

	if ( (int)fighter->query("guilty") > 0 )
		return RANK_D->query_respect(fighter) + 
		"���۷����䣬�������������׼���㴳����ʥ����";

	if ( me->query("assigned_fighter") )
		return RANK_D->query_respect(fighter) + 
		"��������������ս����ʥ�������һ��ʱ�������ɡ�";

	fighter->set_temp("fanyao-asked", 1);

	say("\n��ң˵�����ðɣ����ټ�������������ɢ���������ϣ�����
��ǰ�����ҡ�\n");

	me->set("assigned_fighter", fighter->query("id")); 		
	
	if( !fighter->query_temp("yangxiao-asked") )
	say("\n��ң�ֵ���������ȥ��֪����ʹ���������̴�ͬлΤ������������ʹ��
���������\n");
	message_vision("\n��ң�����뿪��\n\n", fighter);
// 1.2.3.4.
	if(!( room = find_object("/d/mingjiao/square")) )
	room = load_object("/d/mingjiao/square");
	me->move(room);
	for (j = 1; j < 5; j++)
	{
		if( !objectp(monk = present(names[j-1], room) ))
		{
 			me->move("/d/mingjiao/dadian");
			me->delete("assigned_fighter");
			message_vision("\n��ң���˹�����\n\n", fighter);
			return "���ǶԲ�����ɢ�������˲��ڣ��޷����й���ʥ����\n";
		}
		message("vision", "\n��ң���˹�������" + monk->query("name") + "��������˵�˼��䡣\n", room, monk);
		monk->move("/d/mingjiao/westdian");
		message("vision", monk->query("name") + "���˵�ͷ���첽���˳�ȥ��\n", room, monk);
	}
// 5.
	if(!( room = find_object("/d/mingjiao/xingtang")) )
	room = load_object("/d/mingjiao/xingtang");
	me->move(room);
	if( !objectp(monk = present(names[4], room) ))
	{
 		me->move("/d/mingjiao/dadian");
		me->delete("assigned_fighter");
		message_vision("\n��ң���˹�����\n\n", fighter);
		return "���ǶԲ�����ɢ�������˲��ڣ��޷����й���ʥ����\n";
	}
	message("vision", "\n��ң���˹�������" + monk->query("name") + "��������˵�˼��䡣\n", room, monk);
	monk->move("/d/mingjiao/westdian");
	message("vision", monk->query("name") + "���˵�ͷ���첽���˳�ȥ��\n", room, monk);
// 6.
	if(!( room = find_object("/d/mingjiao/dadian")) )
	room = load_object("/d/mingjiao/dadian");
	me->move(room);
	if( !objectp(monk = present(names[5], room) ))
	{
 		me->move("/d/mingjiao/dadian");
		me->delete("assigned_fighter");
		message_vision("\n��ң���˹�����\n\n", fighter);
		return "���ǶԲ����������ڣ��޷����й���ʥ����\n";
	}
	message("vision", "\n��ң���˹�������" + monk->query("name") + "��������˵�˼��䡣\n", room, monk);
	monk->move("/d/mingjiao/westdian");
	message("vision", monk->query("name") + "���˵�ͷ���첽���˳�ȥ��\n", room, monk);
// 7.
	if(!( room = find_object("/d/mingjiao/dadian")) )
	room = load_object("/d/mingjiao/dadian");
	me->move(room);
	if( !objectp(monk = present(names[6], room) ))
	{
 		me->move("/d/mingjiao/dadian");
		me->delete("assigned_fighter");
		message_vision("\n��ң���˹�����\n\n", fighter);
		return "���ǶԲ����Ž������ڣ��޷����й���ʥ����\n";
	}
	message("vision", "\n��ң���˹�������" + monk->query("name") + "��������˵�˼��䡣\n", room, monk);
	monk->move("/d/mingjiao/westdian");
	message("vision", monk->query("name") + "���˵�ͷ���첽���˳�ȥ��\n", room, monk);

        me->move("/d/mingjiao/qiandian");
        call_out("waiting", 1, me);
	return "�ã���Ҷ������ˡ�\n";
}

int waiting(object me)
{
	object fighter;
	int wait_time;

	if( wait_time == 100 )
	{
                say( "��ң˵�����������������ˣ����ǻ�ȥ�գ�\n\n");
		call_out("do_back", 0, me);		
	}

	if( !objectp( fighter = present( me->query("assigned_fighter"), environment(me) ) ) )
	{
		wait_time++;
		call_out("waiting", 1, me);
	}
	else if( !present("yang xiao", environment(me)) || !fighter->query_temp("yangxiao-asked") )
	{
		if( random(10) == 0 ) 
                say("\n��ң˵����" + RANK_D->query_respect(fighter) + "ȥ��������ʹû�У� ���������ڸõ��˰գ�\n");

		wait_time++;
		call_out("waiting", 1, me);
	}
	else 	call_out("preparing", 0, me, fighter);
	return 1;
}

int preparing(object me, object fighter)
{
	object room;

	if(!( room = find_object("/d/mingjiao/qiandian")) )
	room = load_object("/d/mingjiao/qiandian");

        say( "��ң˵��������ɵ��ˣ��粻���ֳ���Ħ����ʥ�����뼴���뿪�˴���\n");

        message("vision", HIY "\n��ң����������������ʥ�����Χ��\n\n" NOR, room);
	command("chat " + fighter->query("title") + fighter->query("name") + 
                "�ڽ���" + NATURE_D->game_time() + "��ս���̹���ʥ����\n");

	fighter->delete_temp("yangxiao-asked");
	fighter->delete_temp("beat_count");
	fighter->set_temp("fighting", 1);

	call_out("fighting",  10, me, fighter, 0);
	return 1;
}

int fighting(object me, object fighter, int count)
{
	object monk1, monk2, room1, room2;

	if(!( room1 = find_object("/d/mingjiao/westdian")) )
	room1 = load_object("/d/mingjiao/westdian");

	if(!( room2 = find_object("/d/mingjiao/qiandian")) )
	room2 = load_object("/d/mingjiao/qiandian");

	if( count <= 6 )
	{
		message("vision", "\n����ʥ�����ٵ���ת�ţ�һ���������ս���\n" NOR, room2);
		monk1 = present(names[count], room1);
		monk1->move(room2);
	}
		
	if( count >= 1 && count <= 7 )
	{
		monk2 = present(names[count-1], room2);
		monk2->move(room1);
	}

	if( !find_player(me->query("assigned_fighter")) ||
	!living(fighter) || fighter->query("qi") <= 1 )
	{
		if( objectp(present(me->query("assigned_fighter"), environment(me)) )) {
			fighter->delete_temp("fighting");
			fighter->delete_temp("beat_count");
		}
		monk1->move(room1);

		say( "��ң˵�����ǰ�����ϧѽ ... ����\n\n");
		command("sigh");
		call_out("do_back", 5, me );
	}
	else if( count >= 7 )
	{
		if( (int)fighter->query_temp("beat_count") >= 14 )
			call_out("do_recruit", 5, me, fighter);
		else
			call_out("do_back", 5, me );
	}
	else
	{
		count++;
		call_out("fighting", 2, me, fighter, count);
	}
 
	return 1;
}

int do_recruit(object me, object fighter)
{
	mapping ft_fam;

	fighter->delete_temp("beat_count");
	fighter->delete_temp("fighting");
	fighter->add("combat_exp", 10000);
	fighter->set("guangming_winner", 1);

	if (!(ft_fam = fighter->query("family")) || ft_fam["family_name"] != "����")
	{
		command("smile");
                say("��ң˵����" + RANK_D->query_respect(fighter) + "�书׿���������������飬Ʒ�¸��ǹ���һ���ң��ʤ���֮����\n");
		call_out("do_back", 5, me );
	}
	else
	{
		say("\n��ң˵�����ã��ã��ã�" + fighter->query("name") + "��û�뵽���г���������һ���˲ţ�\n");
		call_out("do_back", 5, me );
	}
	return 1;
}

int do_back(object me)
{
        object monk, room1, room2;
	int i;

	message("vision", "\n��ңҲ���˻��֣� ��ɢ�˵��漴Ҳ�뿪ǰ�\n", environment(me) );

	if(!( room1 = find_object("/d/mingjiao/qiandian")) )
	room1 = load_object("/d/mingjiao/qiandian");

	room1->set("exits/southdown", "/d/mingjiao/square" );
	room1->set("exits/north", "/d/mingjiao/dadian");
	room1->set("exits/east",  "/d/mingjiao/eastdian");
	room1->set("exits/west",  "/d/mingjiao/westdian"   );

	room1->delete("no_quit");
	if(!( room1 = find_object("/d/mingjiao/westdian")) )
	room1 = load_object("/d/mingjiao/westdian");

	for(i = 1; i <= 7; i ++) 
	{
		switch (i)
		{
		case 1:
		case 2:
		case 3:
		case 4:
			if(!( room2 = find_object("/d/mingjiao/square")) )
			room2 = load_object("/d/mingjiao/square");
			break;
		case 5:
			if(!( room2 = find_object("/d/mingjiao/xingtang")) )
			room2 = load_object("/d/mingjiao/xingtang");
			break;
		case 6:
		case 7:
			if(!( room2 = find_object("/d/mingjiao/dadian")) )
			room2 = load_object("/d/mingjiao/dadian");
			break;
		}
		if( objectp( monk = present(names[i-1], room1) ));
		monk->move(room2);
	}

        me->delete("assigned_fighter");
	me->move("/d/mingjiao/dadian");

	return 1;
}

#include "shizhe.h"
