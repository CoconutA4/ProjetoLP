# ProjetoLP

## Funcionalidades do Trabalho Prático:

### Perfil de ADMINISTRADOR

- **Gerir o Catálogo de Empresas**
  - Criar, editar e remover empresas. :heavy_check_mark: :x:
  - Dados armazenados sobre as empresas: NIF, nome, categoria (Micro, PME, Grande empresa), ramo de atividade, rua, localidade, código postal. :heavy_check_mark:
  - Remoção de empresas só é possível se não houver comentários de utilizadores. Empresas com comentários podem ser marcadas como Inativas. :x:

- **Gerir Ramos de Atividade**
  - Criar, editar e remover ramos de atividade. :heavy_check_mark:
  - Remoção de um ramo é possível apenas se não houver empresas associadas. Caso contrário, o estado do ramo pode ser alterado para Inativo. :heavy_check_mark:
  
- **Visualizar Relatórios**
  - Selecionar no mínimo dois relatórios sobre a utilização da ferramenta pelos utilizadores. :heavy_check_mark:
  - Exemplo de relatórios: listar as palavras-chave mais procuradas. :heavy_check_mark:
  - Relatórios devem ser propostos pelos grupos, considerando o interesse do administrador. :heavy_check_mark:

### Perfil de UTILIZADOR

- **Pesquisar Empresas**
  - Encontrar empresas com base em diversos critérios como nome, categoria, ramo de atividade, localidade, código postal, etc. :heavy_check_mark:
  - Cada grupo deve contemplar 3 critérios diferentes nas pesquisas disponíveis no menu. :heavy_check_mark:

- **Classificar Empresa**
  - Classificar uma empresa de 0 a 5. :x:
  - Relatórios devem incluir a classificação média atribuída à empresa. :x:

- **Comentar Empresa**
  - Comentar uma empresa. :x:
  - Comentários não exigem autenticação, mas nome e email são obrigatórios. :x:
  - Nos relatórios, apenas o nome do utilizador, título e texto do comentário. :x:

## Informações técnicas adicionais:

- **Persistência de dados**
  - Guardar/carregar dados em/de ficheiro para manter os dados entre utilizações.
  - Leitura dos dados implica inicialização em memória, enquanto a gravação substitui os dados no ficheiro pelos existentes em memória.
  - Manipulação de ficheiros pode ocorrer no início e quando o utilizador altera dados na aplicação.

- **Memória dinâmica**
  - Utilizar memória dinâmica sempre que necessário no armazenamento de dados.
