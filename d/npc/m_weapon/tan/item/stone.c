// stone.c
// ����ԭ�ϳ�ʼ״̬

#include <ansi.h>

inherit ITEM;

int do_yelian();
int do_eat(string stone);

void init()
{
	add_action("do_yelian","yelian");
	add_action("do_eat","eat");
}

void create()
{
	set_name( "����ʯ", ({ "butian shi","shi","butian"}));
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ����ʵ�ʯͷ���⻪��˸�����˰������֣��þð��治Ը���¡�\n"
			+"���ʯͷ�ƺ�������ʲô���㲻����ұ��(yelian)һ�£����ܻ���Щʲ\n"
			+"ô����Ķ�������\n");
		set("value", 0);
		set("material", "iron");
	}
}

int do_yelian()
{
	object me,stone,new_ob;
//        int n;
	me=this_player();
	stone=this_object();

	if( (int)me->query("neili") < 50 )
		return notify_fail("������������޷���������ʯ��\n");
	message_vision(HIR "$N��ϥ���������в���ʯ���������ߣ���ʼұ������ʯ��\n" NOR, me);
	me->add("neili",-50);
       me->add_encumbrance( - query_weight());
	switch(random(4) ) {
		case 0:
			new_ob=new("/d/npc/m_weapon/tan/item/jinmu",1);
			new_ob->move(me);			
			message_vision(HIY "����ʯ�������Σ����ڳ���һ����ɫ�Ľ�������\n" NOR, me );
			destruct(stone);
			break;
		case 1:
			new_ob=new("/d/npc/m_weapon/tan/item/shenmu",1);
			new_ob->move(me);			
			message_vision(HIY "����ʯ�����䣬���ڳ���һ�����͸���ľͷ����\n" NOR, me );
			destruct(stone);
			break;
		case 2:
			new_ob=new("/d/npc/m_weapon/tan/item/hanzhu",1);
			new_ob->move(me);			
			message_vision(HIY "����ʯž��һ����������������������ȼ�յ���������\n" NOR, me );
			destruct(stone);	
			break;
		default:
			message_vision(HIY "����ʯ�����������ڻ���һ̲��ˮ������£������ˡ�\n" NOR, me );
			destruct(stone);
	}
	return 1;
}


int do_eat(string stone)
{
	object me;
	int n;
	string stone_name;
	me=this_player();
	stone_name = this_object()->query("id");
	if( !stone || stone!=stone_name )
		return notify_fail("��Ҫ��ʲô?\n");
	n=random(3);
	switch(n) {
		case 0:
			message_vision(HIY "$N���������ˣ�������ʯ�ͿУ�������������ĵ���ʮ����!��Ҳ��ұ������ɵ��\n" NOR,me);
			me->add("food",200);
			me->add("water",200);
			break;
		default:
			message_vision(HIY "$N���������ˣ�������ʯ�ͿУ�������������ĵ���ʮ����!\n" NOR,me);
		}
	destruct(this_object() );
	return 1;
}

