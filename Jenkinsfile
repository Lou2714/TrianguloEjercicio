pipeline {
    agent {
        label 'linux'
    }
    environment { 
        REPO_PRUEBAS = 'https://github.com/Lou2714/PruebasCatch2.git'
        REPO_ESTUDIANTE = 'https://github.com/Lou2714/TrianguloEjercicio.git'
        REPO_PRUEBAS_CREDENTIALS = credentials('ProbandoJenkins')
    }
    stages{
        stage('Preparing enviorement'){
            steps{
                git(
                        url: "${REPO_ESTUDIANTE}",
                        credentialsId: 'ProbandoJenkins',
                        branch: 'main'
                    )
            }
        }
        stage('Checking directoryx2'){
            steps{
                sh 'ls -la'
            }
        }
        stage('Getting test repository'){
            steps{
                git(
                        url: "${REPO_PRUEBAS}",
                        credentialsId: 'ProbandoJenkins',
                        branch: 'main'
                    )
            }
        }
        stage('Checking directory'){
            steps{
                sh 'ls -la'
            }
        }
        stage('Debug') {
            steps {
                sh 'pwd && ls -la'
            }
        }
    }
    post { 
        always { 
            echo 'I will always say Hello again!'
        }
    }
}