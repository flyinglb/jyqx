// murong-fu.c  Ľ�ݸ�

inherit NPC;
inherit F_MASTER;
string ask_bo();
string ask_skill();
string ask_wang();
string ask_dan();
string ask_dan1();
string ask_ge();
string ask_sword(); 
string ask_book();
string ask_book2();
object ob = this_object();

void create()
{
	set_name("Ľ�ݸ�",({"murong fu","murong","fu"}));
        set("title","����Ľ�ݹ���");
        set("nick","�Ա�֮�� ��ʩ����");
	set("long", 
              "���������ºų��Ա�֮��������֮��Ĺ���Ľ�ݸ���\n"
              "�����ϴ��Ų���һ����Ц�ݡ�\n");
        set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
        set("per", 30);
	
	set("max_qi", 3500);
	set("max_jing", 3000);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiali", 0);
        set("combat_exp", 800000);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
        (: perform_action, "parry.xingyi" :) 
        }));
        set_skill("strike",170);
        set_skill("finger",170);
        set_skill("dodge",180);
        set_skill("force", 170);
        set_skill("canhe-zhi", 160);
        set_skill("murong-jianfa",150);       
        set_skill("shenyuan-gong", 180);
        set_skill("yanling-shenfa", 150);   
        set_skill("xingyi-zhang",150);
        set_skill("douzhuan-xingyi", 150);
	set_skill("parry", 180);
	set_skill("sword", 160);
	set_skill("literate", 250);
        set_skill("murong-daofa", 150);
        set_skill("blade",160);
        
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("strike", "xingyi-zhang");
        map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-jianfa");

	prepare_skill("finger","canhe-zhi");
	prepare_skill("strike","xingyi-zhang");
        
        create_family("����Ľ��",2,"����");

       	set("inquiry", ([
                        "name" : "�Ҿ����Ա�֮������ʩ����Ĺ���Ľ�ݸ���\n",
                        "here" : "�����Ǵ��������������룬�ѵ���û����˵����\n",
                        "rumors" : "�Ҹ�ͻȾ�񼲣����������˼����һ�涼û���������¶������Σ�\n",
                        "����" : "�ҵĹ���ס����٢��ɽׯ���������������µ������񶴡�\n",
                        "��ʩˮ��" : (: ask_ge :),
                        "Ľ�ݲ�" : (: ask_bo :),
                        "��Ԫ��" : (: ask_dan :),
                        "����" : (: ask_book :),
                        "������" : (: ask_wang :),
                        "����" : (: ask_sword :),
                       	"��ת����"  : (: ask_skill :),
                        "��¶����ɢ" : (: ask_dan1 :),
                        "ͼ��" : (: ask_book2 :)
        ]));
                
        set("dan_count", 1);
       	set("book_count",1);
        set("book2_count" ,1);
        set("dan1_count", 2);
	setup();
        carry_object("/clone/misc/cloth")->wear();
}

int count = 0;

void reset()
{
    count = 1 - count;
    if (count) return;
        set("dan_count", 1);
        set("book_count",1);
        set("book2_count" ,1);
        set("dan1_count", 2);
}

void init()
{
        add_action("do_jiaoliang", "jiaoliang");
        ::init();
}

void attempt_apprentice(object ob)
{
        if (ob->query_skill("parry", 1) < 100) {
		command("say �ҹ���Ľ���Ա�֮������ʩ������м�Ҫ�����ߣ�С�ֵ��ƺ�����ѧϰ��");
		return;
	}

        if (ob->query_skill("shenyuan-gong", 1) < 100) {
		command("say �ҹ���Ľ���Ա�֮������ʩ������ڹ��ķ�Ҫ�����ߣ�С�ֵ��ƺ�����ѧϰ��");
		return;
	}

        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say �������ϣ����ҹ���Ľ���ֵ�һ���ģ�Ϊ�����Ҵ������һ��������");
        //command("chat ����������һ���ģ������˸�ָ�տɴ�����");
        //command("chat* haha"); 
	command("recruit " + ob->query("id"));
}

 

string ask_wang()
{
mapping fam;
// obiect ob;
        if (!fam = this_player()->query("family") || fam["family_name"] !="����Ľ��")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
        return "�������ұ��ã�һֱ������ܵĺ��ϣ����Ҷ��ܳ�ʱ��û�м������ˡ�\n";
}

string ask_skill()
{
mapping fam; 
// object ob;
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        return "��ת��������Ľ�ݼҵľ�ѧ������ע���мܺ�����\n";
}

string ask_ge()
{
mapping fam; 
// object ob
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        return "��ʩˮ������Ľ���ղ������ؼ�֮���ڣ����ҵ���.....\n";
}

string ask_sword()
{
mapping fam; 
// object ob;
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        return "��������ү�����ź��������ð�������������úñ��ܣ�\n";
}

string ask_book()
{
	object ob;
	mapping fam; 
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
        if ( fam["master_name"] != "Ľ�ݲ�" && fam["master_name"] != "Ľ�ݸ�")
      	        return RANK_D->query_respect(this_player()) + 
		"��������������̸������";

	if (  present("douzhuan xingyi", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����ж�ת���Ƶ��伮�����ô����Ҫ�ˣ� ����̰�����У�";

	if (query("book_count") < 1) return "�Բ��𣬶�ת���Ƶ��伮�Ѿ�������Ҫ���ˡ�";

	ob = new(__DIR__"obj/shu1");
	ob->move(this_player());

	add("book_count", -1);

	message_vision("$N�õ�һ����ת���Ƶ��书�ؼ���\n",this_player());
	return "�ðɣ�����ΪĽ�ݼ����Ĺ������Ȿ��ʹ�����ɡ�";

}

string ask_book2()
{
	object ob;
	mapping fam; 
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
        if ( fam["master_name"] != "Ľ�ݲ�" && fam["master_name"] != "Ľ�ݸ�")
      	        return RANK_D->query_respect(this_player()) + 
		"��������������̸������";
        if ( (int)this_player()->query_skill("douzhuan-xingyi",1)<50)
                return RANK_D->query_respect(this_player()) + 
		"��������������̸����ȡͼ�⣿";
	if (  present("douzhuan xingyi", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����ж�ת���Ƶ��伮�����ô����Ҫ�ˣ� ����̰�����У�";

	if (query("book2_count") < 1) return "�Բ��𣬶�ת���Ƶ��伮�Ѿ�������Ҫ���ˡ�";

	ob = new(__DIR__"obj/shu2");
	ob->move(this_player());

	add("book2_count", -1);

	message_vision("$N�õ�һ����ת���Ƶ��书�ؼ���\n",this_player());
	return "�ðɣ�����ΪĽ�ݼ����Ĺ������Ȿ��ʹ�����ɡ�";

}
 
string ask_dan()
{
	mapping fam; 
        object ob, me; 
        me = this_player();
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

        if ( (int)this_player()->query_condition("medicine" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"���ǲ��ǸճԹ�ҩ����ô����Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

        if ( (int)this_player()->query("max_neili" ) < 400)
		return RANK_D->query_respect(this_player()) + 
		"������������ҩ����к����ˣ�����ʱ�������ɡ�";
        
        if ((int)me->query("max_neili") >= (int)me->query_skill("force")*10)
                return RANK_D->query_respect(this_player()) + 
                "���������ҩ��,���书�Ѿ�����,ȥ���������Ϊ��.";
        
        if (  present("guiyuan dan", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����п�ҩ������ô����Ҫ�ˣ� ����̰�����У�";

	if (query("dan_count") < 1) return "�Բ��𣬹�Ԫ���Ѿ�������Ҫ���ˡ�";

             ob = new("/d/murong/obj/guiyuan-dan");
	ob->move(this_player());

	add("dan_count", -1);

	message_vision("$N���һ�Ź�Ԫ����\n",this_player());
	return "�ðɣ��˵�������������һ�������Ṧ���������Ҿʹ�����ɡ�";

}

string ask_dan1()
{
	mapping fam; 
        object ob,me;
        me = this_player();
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

        if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"���ǲ��ǸճԹ�ҩ����ô����Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

        if ( (int)this_player()->query("max_neili" ) < 100)
		return RANK_D->query_respect(this_player()) + 
		"������������ҩ����к����ˣ�����ʱ�������ɡ�";

	if (  present("qingxin san", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����п�ҩ������ô����Ҫ�ˣ� ����̰�����У�";
	
	if (query("dan1_count") < 1) return "�Բ�����¶����ɢ�Ѿ�������\n";

	ob = new(__DIR__"obj/qingxin-san");
	ob->move(this_player());

	add("dan1_count", -1);

	message_vision("$N���һ����¶����ɢ��\n",this_player());
	return "�ðɣ���ҩ������������һ�������Ṧ���������Ҿʹ�����ɡ�\n";

}

string ask_bo()
{
        mapping fam; 
//        object ob;
	if ((int)this_player()->query_temp("marks/ʧ��")) 
                 return" Ľ�ݸ����з����������⣬ֱ��" + this_player()->name() 
                 + "һ��һ��˵�����Ѿ��������ˣ������ỹ����ȥ����������!\n";
		 
	 
         if (!(fam =this_player()->query("family")) || fam["family_name"] != "����Ľ��")
                return "���뱾��������������֪�˻��Ӻ�̸��\n";
  
        if ((int)this_player()->query_temp("marks/bai_bo") && fam["master_name"] == "Ľ�ݲ�") 
                return "���Ѿ��ǼҸ��ĵ����ˣ�����������ѧ��!\n";

        this_player()->set_temp("marks/jiao", 1);
        return "Ľ�ݸ����з����������⣬ֱ��" + this_player()->name() 
        + "һ��һ��˵�����Ҹ����������֣���������Ի������书δ�ɣ�
        ��ò�Ҫȥ��ȥ���裬������������ܽ�����ʮ�У��ͺ��ҽ���һ�¡�(jiaoliang) \n";
                
	 
}

int do_jiaoliang()
{
	object me, obj, jiaxin;
	int current_qi, count;

	me = this_object();
	obj = this_player();
        jiaxin = new("/d/murong/obj/jiaxin");
	current_qi = (int)me->query("qi");

	say(obj->name() + "��Ľ�ݸ�˵���ðɣ��Ǿ���ʦ��ָ�㼸�� ��\n");
        set("max_qi", 3500);
        set("jiali", 100);
        set("neili", 3500);
        set("max_neili", 3500);
        set("max_jing", 2000);
        if( obj->query_temp("marks/jiao") ) {
                obj->set_temp("marks/jiao", 0);
		count = 0;
		while ( ((int)obj->query("qi")*100 / (int)obj->query("max_qi")) > 30) { 
			if ( !present(obj, environment()) )
				return 1;
                        COMBAT_D->do_attack(obj, me, obj->query_temp("weapon"));
			if (((int)me->query("qi")*100/current_qi)< 30 || ++count > 10) {
				say(
"Ľ�ݸ���" + obj->name() + "˵���� ������Ľ�������ֳ����ģ������д����ţ� �����϶���ǰȥ���֣�\n"
"�������������˼ҡ�ϣ�����ܲ�������������Ľ�����ң��⸴�������\n"
				);
                                jiaxin->set("is_murong_fu",1);
      				jiaxin->move(obj);
				obj->set_temp("marks/bai_bo", 1);
			        message_vision("$N����$nһ�����\n", me, obj);
				return 1;
			}
	                 COMBAT_D->do_attack(me, obj);
		}
	 	say(
"Ľ�ݸ�����" + obj->name() + "����˵�������书δ�ɣ��ͺø���Զ,\n"
"�㻹�ǰ�������ȥ��!\n"
		);
               this_player()->set_temp("marks/ʧ��", 1);
         }
	return 1;
} 


