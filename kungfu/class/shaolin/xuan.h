// xuan.h for fight and get letter from Xuan

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping my_fam  = me->query("family");
	mapping ob_fam  = ob->query("family");

	if ( ob->query_temp("have_letter") && present("tuijian xin5", ob) ) 
	{
		command("say �������������ҵ��Ƽ���ȥ��ʦ���� ?");
		return 0;
	}
        
	if (obj->query("id") == "tuijian xin4" 
	&& ob->query_temp("have_letter") )
	{
		ob->set_temp("apprentice_ok",1);
	        command("say �ã�" + ob->query("name") + "����Ը�����Ϊʦ��");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}

        command("smile");
        command("say �ⶫ�����ҿ�û��ʲ���á�");
        command("give " + obj->query("id") + " to " + me->query("id"));
	return 0;

}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name;

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) )
	{
		command("say " + ob_fam["master_name"] + "��ͽ�������ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");
	
			command("say ��" + ob_fam["master_name"] + "���������ҵİɣ������� !");
			command("say ƶɮ�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");

			name = ob->query("name");
			new_name = "��" + name[2..3];
			ob->set("name", new_name);
	
			command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����ɳ��ֱ����� !");
			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "����û���Ƽ��ţ�����Խ����ʦ��");
			return;
		}
	}

	return;
}

