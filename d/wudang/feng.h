// feng.h 
// by Marz 

#include <ansi.h>

int look_feng(string arg);

int look_feng(string arg)
{
	int lucky;
	object me;

	if( !arg || arg!="feng" ) return 0;
	write("

                      ^
                     ^ ^
                   @@@__^    
                    ^ @@@__
                   ^   ^  ^

̧����ȥ������ƬƬ���������ƣ��������������֣���ң���ɼȡ�\n\n");

	me = this_player();
	lucky = random(me->query_dex() + me->query_kar()) + me->query_dex();

	if (lucky > 58)
	{
		write("ͻȻ�䣬�и��ڵ���������һ�Ӷ�����������һֻ���\n"
			+"������ô�ߵĵط�����ô�����أ���������Ҳ����һʱ�����ۡ�\n\n");
	
	}else if(lucky >= 45)
	{
		// do nothing here
	}else if(lucky >= 30)
	{
		message_vision(HIY"$N����ſ��죬һ���������̤�˸��գ�... ��...��\n\n"NOR, me);
		message_vision(HIY"$Nһ������ˤ��һ�ӣ����ã�ֻ����ЩƤ�ǣ�û�й���ȥ��\n\n"NOR, me);
		me->receive_damage("qi", 30+4*random((int)me->query("age")));
		me->receive_damage("jing", 50);
	}else // bad luck 
	{
		message_vision(HIR"$N�����̧ͷ���죬һ���������̤�˸��գ�... ��...��\n\n"NOR, me);
		tell_object(me, HIR"����Ʋ�ס��ֱ��ɽ�¹���ֻ���û����޴����ۣ�ʹ��Ҫ������ȥ��\n\n"NOR);
		me->move(__DIR__"tyroad8");
		message("vision", HIR"ֻ��" + me->query("name")
			+ "��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�������������\n\n"NOR,
			environment(me), me);
		me->unconcious();
	}
	
	return 1;
}
