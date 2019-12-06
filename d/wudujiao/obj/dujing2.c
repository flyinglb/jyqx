// dujing2.c

inherit ITEM;

void create()
{
	set_name("������ƪ", ({ "jing", "book" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������С�ᣬ������������ļ����˸����ö��ķ��ţ�������(kan)��һ����\n");
              set("no_drop", "�������������뿪�㡣\n");
		set("value", 0);
		set("material", "silk");
	}
}
void init()
{
	add_action("do_read", "kan");
	add_action("do_read", "see");
	add_action("do_read", "du");

//	this_object()->set("created", 1);
	remove_call_out ("destroy_book");
	call_out ("destroy_book", 28800); // 8 hours
 	
}

void destroy_book()
{
	message_vision("һ��紵����" + (string)this_object()->query("name") + "ƬƬ���䣬����ȥ�ˡ�\n", environment(this_object()));
	destruct(this_object());
}

int do_read(string arg)
{
	object me;
	int jing_cost, gain;
	me=this_player();
     	if( !arg||!( arg == "jing"||arg =="book"))
        	return notify_fail("ʲô��\n");
    	if( me->is_busy() )
        	return notify_fail("������æ���أ����п��ܾ����ж�...\n");
   	if( me->is_fighting() )
        	return notify_fail("���ڲ��뵽���ж�����̫���˰ɣ�\n");
       if ((string)me->query("family/family_name")!="�嶾��"){
        	remove_call_out ("destroy_book");
	       call_out ("destroy_book", 0); 
        }
    	if( (int)me->query_skill("duji",1)<150
        ||(int)me->query("combat_exp")< 300000 )
		return notify_fail("�㿴����ȥ������û�����Ȿ����д�Ķ���ɶ��\n");
	if( (int)me->query_skill("duji",1)>300 )
		return notify_fail("��Ķ����Ѿ��������裬�Ȿ�鲻�����㳤�����١�\n");

	jing_cost = 35 + (20-(int)me->query("int"));
	if( (int)me->query("jing")<jing_cost )
		return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");	
	me->receive_damage("jing", jing_cost);

	gain = (int)me->query_skill("duji", 1)/4+(int)me->query_skill("literate",1)/2;
	me->improve_skill("duji", gain);

    	message_vision("$N���ž����ϸ�Ķ�,ֻ���������ص������ö����˵�\n������������δ�ţ����ſ��Ž���ס����һ���亹��\n", me);
		
	return 1;
}
