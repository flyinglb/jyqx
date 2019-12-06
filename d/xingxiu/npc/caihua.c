// npc: /d/xingxiu/npc/caihua.c
// Jay 5/13/96

inherit NPC;

void create()
{
        set_name("�ɻ���", ({ "caihua zi", "caihua" }) );
        set("gender", "����" );
//	set("title", "��������");
	set("nickname", "������");
        set("age", 38);
        set("long", 
             "�ɻ����������ɵ�һ��С��ޣ��书�䲻�ã���������а��"
	     "�����������Ҹ�Ů���ǹٸ�ͨ���ķ��ˣ��ʶ�������������"
	     "Ҳ��������������ӡ�\n");
        set("str", 25);
        set("dex", 30);
        set("con", 17);
        set("int", 15);
        set("shen_type", -1);

        set_skill("unarmed", 20);
	set_skill("force", 50);
        set_skill("dodge", 95);
	set_skill("zhaixinggong", 95);
	map_skill("dodge","zhaixinggong");

        set("combat_exp", 25000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

        create_family("������", 5, "����");

        set("attitude", "peaceful");
        set("inquiry", ([
            "name" : "��Ҳ�ǲ�����������˭�ˣ��������������źŲɻ��ӡ�",
            "�ɻ�" : "�ǿ���ѧ�ʣ��Ҳ������̡�",
       ]) );

        setup();
        carry_object("/d/city/obj/pink_cloth")->wear();
        add_money("silver", 10);
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if (myfam && myfam["family_name"] == "������") 
          command("say �������ɽ��׽�˸�С�����ˮ�鼫�ˣ��͹����ҵ���ң����"
		+"����Ҫ��Ҫ��ȥ���ԣ�");
	me->set_temp("marks/��",0);

}


void attempt_apprentice(object ob)
{
	command("hehe");
	command("say ��ѧ�ҵĲɻ��񼼣�û�Ŷ���");
	return;
}

int accept_object(object me, object obj)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if (!myfam || myfam["family_name"] != "������") 
	  command("say �ٸ����׽�����");
	else {
	  if (!obj->query("money_id")) {
 	    if (me->query("gender")=="Ů��") {
	  	command("kiss " + me->query("id"));
		command("say �벻��ʦ��Ҳ��������á�");
	    }
	    else {
		command("bow " + me->query("id"));
                command("say ��лʦ�֡�");
            }
            command("say �Բ�����С��������ϱ���֪���ĸ��쵰�����ˣ�����"
			+ "����Խ���˯һ����");
	    me->set_temp("marks/��", 1);
          }
          else {
		command("thank " + me->query("id"));
		command("say Ǯ���е��ǣ��㻹�Ǹ��ҵ���ʲô�ɡ�");
          }
        }
        return 1;
}

