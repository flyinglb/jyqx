
inherit NPC;
void greeting(object ob);
string inquiry_map();

void create()
{
        set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
        set("long", "���ǰ���ɽׯ�����ųơ���������ŷ���档\n"
                   +"����ϰ���������澭���߻���ħ���ѱ�þ�\n"
                   +"����ң�������ͷɢ�����¹ڲ�����\n");
        set("title", "�϶���");
        set("gender", "����");
        set("age", 53);
        set("nickname","����");
 
        set("attitude", "peaceful");
 
        set("str", 30);
        set("int", 24);
        set("con", 30);
        set("dex", 24);
 
        set("qi", 500);
        set("max_qi", 500);
        set("jing", 300);
        set("str", 30);
        set("int", 24);
        set("con", 30);
        set("dex", 24);
 
        set("qi", 500);
        set("max_qi", 500);
        set("jing", 300);
        set("max_jing", 300);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
 
        set("combat_exp", 1500000);
        set("score", 200000);
        set_skill("force", 200);
        create_family("����ɽ��",1, "��ɽ��ʦ");

   // other set needed for future use.
        set("class", "taoist");
        set("inquiry", ([
        "��ͼ": (: inquiry_map :),
        ]));

        setup();
}
 
void init()
{
        object ob;
 
        ::init();
 
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch(random(3)) {
        case 0:write("����˭����Ҫɱ���㣡������������");
                break;
        case 1:write("˭˵�ҷ��ˣ���û���");
                break;
        }
}
string inquiry_map()
{
//        object ob;
	object me=this_player();
	if((string)me->query("family/family_name")!="����ɽ��")
		return "�����ܰ����ܸ��������ӡ�����Ϊ�����ɶ����֪�����𣿹���";
	else
	{
		if(me->query("combat_exp")<=10)
			return "�ߣ���հ���ʦ���������ǣ��ѵ��뵱������С���������㣡";
    message_vision("ŷ����΢΢һЦ���ս�$N�Ķ�����С���ֹ�������",me);
    command("tell "+(string)me->query("id")+
              "���Ǵ��߳�ɳĮ����ȷͨ·����Ҫ����ϸ��������");
    command("smile");
    return "��ס�˰ɡ�";
   }
}
/*string inquiry_map()
{
 object ob,room=enviroment();
 object me=this-player();

 if((string)me->query("family/family_name")!="��ͷɽ��")
   return "�����ܰ����ܸ��������ӡ�����Ϊ�����ɶ����֪�����𣿹���";
 else
  {
    if(me->query("combat_exp")==0)
     return "�ߣ���հ���ʦ���������ǣ��ѵ��뵱������С���������㣡";
    if(!objectp(present("key",enviroment(me))))
        return "��û��ʲôkey�ۣ�";
    if(present("key",me))
        return "��С����ô̰�����ᣡ";
    if(me->query("combat_exp")<1500)
        return "�����ʵս�����ٸ�Щ��Ϊʦ���ٸ����㡣";
    ob=new(__DIR__"../obj/key");
    ob->move(room);
    return "���Ǻ��ŵ�key,����ȥ�ɡ�";
   }
} */



