// liwu.c
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
        
}


void create()
{
set_name("����", ({"liwu"}));
        set("unit", "��");
        set("long", "�����½�ӹȺ��Ϊ�����׼�������\n
                        ����д��"+HIY"��ӭ�����롼�½�ӹȺ��������������!"NOR+"\n");
    set("no_give", "��Ҫ�����Խ�Ӵ!\n");
        set("value",100);
        setup();
}

int do_eat(string arg)
{
        object me=this_player();
        if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if(arg=="liwu")
        {
                me->add("max_neili",100);
                me->add("combat_exp",10000);
                me->add("max_jingli",20);
                me->add("potential",3000);
                me->set("neili",me->query("max_neili"));
                me->set("eff_qi",me->query("max_qi"));
                me->set("qi",me->query("eff_qi"));
                message_vision("$N�������"+HIR"����"NOR+",��һ��˵�����ĵ�"+HIB"���"NOR+"��!\n",me);

                destruct(this_object());
        }
        return 1;
}

