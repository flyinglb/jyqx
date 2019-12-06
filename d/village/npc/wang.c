// wang.c

inherit NPC;
#include <ansi.h>;
int ask_me();

void create()
{
        set_name("��С��", ({ "wang xiaoer", "wang" }) );
        set("gender", "����" );
        set("age", 21);
        set("long", "���Ǹ����͵Ĺ������ӣ�һ���뺷֮ɫ��\n");
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
        set("combat_exp", 5000);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);

	set("shen_type", -1);
        set("str", 28);
        set("dex", 25);
        set("con", 20);
        set("int", 17);
        set("book_count", 1);
        set("attitude","heroism");
        set("inquiry", ([
		"��С��" : "�Ǿ����Ұ�...",
		"��" : (: ask_me :),
		"͵��" : (: ask_me :),
        ]) );
        setup();
        add_money("silver", 10);
}
void init()
{
        ::init();
        add_action("do_bihua", "bihua");
}

int ask_me()
{
	if ((int)this_player()->query_temp("marks/��3")) {
		say(
"��С����¶�׹⣬��" + this_player()->name() + "������ɱ�˲���ͷ��أ����Ѿ�\n"
"�������㻹���Ź��ң����Ӹ���ƴ��!\n");
		set_temp("apply/attack", 30);
     		set_temp("apply/defense", 30);
		this_object()->kill_ob(this_player());
		return 1;
	} else {
	say(
"��С������" + this_player()->name() + "һ�ۣ������ں���˵����\n"
"����������͵�ģ���Ҫ������?! ����Ҳ�ǳ����������ģ��ѵ�\n" 
"��֪������˭��ȭͷ��˭˵��?! �㲻����? �Ǻã����������У�\n"
"Ҫ����Ӯ�ˣ������ϰ�˫���������̫̫�������һ����������\n"
"��������Ҫ���ˣ��͸������ų�ȥ�������ţ��Ҳ��ұȻ�(bihua)����?\n");
	this_player()->set_temp("marks/��2", 1);
	return 1;
	}
}

int do_bihua()
{
	object me, obj, book;
	int current_qi;

	me = this_object();
	obj = this_player();
	if (query("book_count") < 1)
	{
		write("��С������" + obj->name() + "���˰��ۣ�����û�գ������ҹ����������ү�����Ρ�\n");
		return 1;
	}
	add("book_count", -1);
	book = new("/clone/book/sword_book");
	current_qi = (int)me->query("qi");

	say(obj->name() + "����С��˵���ðɣ���" + RANK_D->query_self_rude(obj) + 
"��ͬ�������С�\n");
        if( obj->query_temp("marks/��2") ) {
                obj->set_temp("marks/��2", 0);
		while ( ((int)obj->query("qi")*100 / (int)obj->query("max_qi")) > 50) { 
			if ( !present(obj, environment()) )
				return 1;
                        COMBAT_D->do_attack(obj, me, query_temp("weapon"));
			if (((int)me->query("qi")*100/current_qi)< 50) {
				say(
"��С����" + obj->name() + "˵���������Ӯ���ң���˵ʲô�Ҷ������ţ�����Ͱ�\n"
"Ǯ����̫̫��ȥ�����⣬�Ȿ��Ҳ�������ˡ�����ǰЩ���ӻ�ɽ�ɴ���\n"
"·����������Ъ��ʱ���µġ�\n"
				);
      				book->move(obj);
      				add("book_count",-1);
				obj->set_temp("marks/��3", 1);
			        message_vision("$N����$nһ���顣\n", me, obj);
message("channel:rumor", HIM"��"+HIR+"ҥ��"+HIM+"��"+HIR+"ĳ�ˣ�"+this_player()->query("name")+"������ɽ�����ˡ�\n"NOR, users());
				return 1;
			}
	                 COMBAT_D->do_attack(me, obj);
		}
		say(
"��С������" + obj->name() + "Ʋ��Ʋ�죬˵����������㱾�»���\n"
"��Ӣ��?!���ҹԹԵ�����ȥ��!\n"
		);
                message("vision",
obj->name() + "�ԹԵ�ſ�ڵ��ϣ��Ӷ������˳�ȥ��\n", environment(obj), ({obj}) );
                obj->move("/d/village/temple1");
                message("vision",
obj->name() + "�Ӷ������˳�����\n", environment(obj), ({obj}) );
                return 1;
	}
	say("��С�����ͷ��Ķ�" + obj->name() + "˵����Ҫ��Ͷ��֣�����ʲô!\n"
	);
	return 1;
}
