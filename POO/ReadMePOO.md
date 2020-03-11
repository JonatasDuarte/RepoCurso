# My README for OOP discipline

- *Just some instructions on Terminal/Prompt:*  
1. No bloco de notas, crie os arquvios .java  
2. Adicione-os em uma pasta  
3. Crie as pastas: bin, dist, src  
4. Pega os endereços  
5. No endereço, use o comando: javac nome.java  
6. No endereço, use o comando: java nome  
7. No endereço, use o comando: src\*.java -d bin  
8. No endereço jar, use o comando: jar --create -- file dist\myapp.jar --main-class=nome -C bin\  
9. No endereço jar: -jar dist\myapp.jar  
10. Após o package, no srccria as pastas no caso br, dentro dele edu e por fim ifpb com os .java  
11. No endereço, javac usa src/br/edu/ifpb/*.java -d bin  

---  
- *Comandos Java:*  
* java NomeArq.java  (Executa arquivo .java)  
* javac -d bin ARQ.java (Cria o nosso .class e adiciona na pasta 'bin') // (-d indicação do destino de onde o .class será gerado)  
* jar cvfe Nome.jar NameClass NameClass.class (criar o .jar dentro do mesmo diretorio e usando as classes no mesmo diretorio)  

---
- *Gerando arquivo maven via terminal* 
   mvn archetype:generate -DgroupId=br.edu.ifpb -DartifactId='teste' -DarchetypeArtifactId=maven-archetype-quickstart -DarchetypeVersion=1.4 -DinteractiveMode=false  
---  
- *Alterando nosso **.pom** no Maven:*  
```XML  
<configuration>
       <archive>
          <manifest>
             <mainClass>'br.edu.ifpb.App'</mainClass>
          </manifest>
      </archive>
  </configuration>  
  ```  

  - *Remover **<properties>** do pom criado e colocar:*  

```XML
<name>Nome do projeto</name>
    <url>http://www.minhaempresa.com/site</url>
    <description>A very important project here</description>
    <packaging>jar</packaging>

    <properties>
        <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>
        <project.reporting.outputEncoding>UTF-8</project.reporting.outputEncoding>
        <java.version>'11'</java.version>
        <maven.compiler.source>${java.version}</maven.compiler.source>
        <maven.compiler.target>${java.version}</maven.compiler.target>
    </properties>
```

- *Remover:*  
```XML
    <plugin>
        <artifactId>maven-jar-plugin</artifactId>
        <version>3.0.2</version>
    </plugin>
``` 
- *Adicionar:*
```XML
	    <plugin>
                <groupId>org.apache.maven.plugins</groupId>
                <artifactId>maven-jar-plugin</artifactId>
                <version>3.1.1</version>
                <configuration>
                    <archive>
                        <manifest>
                            <addClasspath>true</addClasspath>
                            <mainClass>br.edu.ifpb.App</mainClass>
                        </manifest>
                    </archive>
                </configuration>
         </plugin>
```

