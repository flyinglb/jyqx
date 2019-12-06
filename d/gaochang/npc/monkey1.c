// monkey.c 
inherit NPC;
void create()
{
    set_name("ȳ�ȵĺ���", ({ "monkey" }) );
    set("race", "Ұ��");
    set("long",
        "��ֻ����ȳ�������ȣ������Ͱ͵������㡣\n");
    set("combat_exp", 5000);
    set("attitude", "peaceful");
    set("limbs", ({ "ͷ��", "����", "צ��", "β��" }) );
    set("verbs", ({ "bite" }) );
    set("apply/attack", 10);
    set("apply/defense", 10);
    set_skill("unarmed", 25);
    set_skill("parry", 20);
    set_skill("dodge", 20);
    setup();
}
void init()
{
     object me=this_player();
     if (userp(me) && !query_leader()){
       set_leader(me);
       add_action("do_bandage","bandage");
     }
}
int do_bandage(string arg)
{
     object kuzhi;
     object me=this_player();
     if (!arg || !living(this_object()) || !objectp(kuzhi=present("duan zhi",me)))
        return 0;
     if (!this_object()->id(arg))
         return 0;
    if (query("name")=="����") return 0;
     message_vision("$N�öϵ��Ŀ�֦Ϊ$n������ȳ�ȡ�\n\n\n",me,this_object());
     destruct(kuzhi);
     set_name("����", ({ "monkey" }) );
    set("long",
        "��ֻ���Ӹм��������㡣\n");
     message_vision("$n���˵ط��˼���������\n\n",me,this_object());
     call_out("do_get_book",3,me);
     return 1;
}
int do_get_book(object me)
{
    object book;
      if (!me || environment(me)!=environment(this_object()) || !living(this_object()) ){
     set_leader(0);
     return 1;
     }
     if (base_name(environment(this_object()))!=("/d/gaochang/room70")){
         call_out("do_get_book",3,me);
         return 1;
     }
    message_vision("$N���ҷ���ȡ��һ���Ͳ����ŵ��齻��$n\n",this_object(),me);
    book=new("/d/gaochang/obj/jiuyangbook");
    book->move(me);
    message_vision("$N����һ����������˼����������ˣ�\n",this_object());
    destruct(this_object());
    return 1;
}
