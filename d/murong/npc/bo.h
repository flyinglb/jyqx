// bo.h
void attempt_apprentice(object ob)
{
        object me;
        me=this_player();
         string *prename =
	 ({ "��","Ľ" });
        string name, new_name;
//	name = ob->query("name");
 
        if (present("jiaxin", me))
         {  destruct(present("jiaxin",me));

           command("say �ðɣ���Ȼ" + RANK_D->query_respect(ob) + "���Ҷ����ż�����Ϊ��" +
		"��������������Ҿ�������ɡ�");
           name = ob->query("name");
           new_name = prename[random(sizeof(prename))] + name[0..1];
	   ob->set("name", new_name);
           command("say �ӽ��Ժ���ͽ���" + new_name + "��ϣ�����ܰ�Ľ�ݹ�������");
           command("recruit " + ob->query("id"));
           command("chat* ����һЦ��˭�� �Ա�֮�� ��ʩ���� ����������");
           command("chat* haha"); 
         }
        else
          command("say ��Ľ�ݲ����������ͽ!");
        return;
           
}
